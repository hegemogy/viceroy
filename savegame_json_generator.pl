#!/bin/env perl
use strict;
use warnings;
use Path::Tiny qw(path);
use Data::Dumper;
use JSON;

our $INDENT = " " x 4;

my @lines;
{
    my $content = path('savegame.h')->slurp;
    my $close   = '} __attribute__ ((packed));';
    $content =~ s/[\s\S]+struct savegame \{.*([\s\S]+)\Q$close\E/$1/;
    $content = simplify_map($content);
    @lines   = grep m/\S/, split "\n", $content;
}
my @id = ();
my %DATA;
my $ORDER;
my $leading;
foreach my $line (@lines) {
    if ( $line =~ m|^\s*//.*| ) {
        $leading = $line;
        $leading =~ s/^\s+//;
        $leading =~ s/\s+$//;
        next;
    }
    my $id_string = ( join '.', @id );
    my $struct    = get_struct($line);
    if ($struct) {
        push @id, $struct;
        next;
    }
    my ( $chunk, $name, $suffix, $hints ) = get_chunk($line);
    if ($chunk) {
        my $bytes = get_bytes( $chunk, $suffix );
        if ($leading) {
            $hints = "$leading,$hints";
            $leading = '';
        }
        $hints =~ s/\n//g;
        set_data( \%DATA, $bytes, $hints, @id, $name );
        next;
    }
    if ( is_return($line) ) {
        pop @id;
        next;
    }
    die "DATA=" . Dumper( \%DATA ) . " line=$line id=$id_string";
}

sub set_json {
    my (@keys)     = @_;
    my $key_string = join '.', @keys;
    return 'j["' . ( join '"]["', @keys, 'value"]' ) . " = sg->$key_string;";
}

sub set_json_section {
    my ( $data, $section ) = @_;
    my @lines;
    while ( my ( $key, $value ) = each %{ $data->{$section} } ) {
        if ( $value->{order} ) {
            push @lines, set_json( $section, $key );
        }
        else {
            foreach my $subkey ( keys %{$value} ) {
                push @lines, set_json( $section, $key, $subkey );
            }
        }
    }
    return @lines;
}

sub render_merge_function {
    my ( $data, $section ) = @_;
    my @lines        = set_json_section( $data, $section );
    my $lines_string = join "\n$INDENT", @lines;
    return <<ENDTEXT;

json merge_json_$section(        const struct savegame *sg, json j )
{
    $lines_string
    return j;
}
ENDTEXT
}

#TODO j["player_list"][i]["nation"]["value"] = nation_list[i];
sub render_merge_list_function {
    my ( $data, $section ) = @_;
    my $section_list = $section . "_list";
    my @lines        = set_json_section( $data, $section );
    my @loop_lines;
    foreach my $line (@lines) {
        $line =~ s/$section"]/$section_list"][i]/;
        $line =~ s/$section\./$section\[i\]./;
        push @loop_lines, $line;

    }

    my $joiner            = "\n" . ( $INDENT x 2 );
    my $loop_lines_string = join $joiner, @loop_lines;
    return <<ENDTEXT;

json merge_json_$section_list(   const struct savegame *sg, json j )
{
    json base = j["$section"];

    for (int i = 0; i < 4; ++i) {
        j["$section_list"][i] = base;
        $loop_lines_string
    }
    return j;
}
ENDTEXT
}

my $all_functions = join "\n",
    (
    map { render_merge_function( \%DATA, $_ ) } 'head',
    'other', 'stuff', 'tail'
    ),
    ( map { render_merge_list_function( \%DATA, $_ ) } 'player' );

my $json = JSON->new->pretty->encode( \%DATA );

# )" is our terminator, so we can't have it in our output
$json =~ s/\)"/) "/g;

path('savegame_json.h')->spew(<<ENDTEXT);
// THIS FILE WAS AUTO-GENTERATED FROM savegame.h
// json support, 'using json ...' is for convenience
#include <iostream>
#include <json.hpp>
using json = nlohmann::json;

json json_base();
void print_json(             const struct savegame *sg );
json merge_json_head(        const struct savegame *sg, json j );
json merge_json_other(       const struct savegame *sg, json j );
json merge_json_stuff(       const struct savegame *sg, json j );
json merge_json_tail(        const struct savegame *sg, json j );

json merge_json_player_list( const struct savegame *sg, json j );

/*
json merge_json_colony_list( const struct savegame *sg, json j );
json merge_json_unit_list(   const struct savegame *sg, json j );
json merge_json_nation_list( const struct savegame *sg, json j );
json merge_json_tribe_list(  const struct savegame *sg, json j );
json merge_json_indian_list( const struct savegame *sg, json j );
json merge_json_map(         const struct savegame *sg, json j );
*/

void print_json( const struct savegame *sg )
{
    json j = json_base();

    j = merge_json_head(        sg , j );
    j = merge_json_other(       sg , j );
    j = merge_json_stuff(       sg , j );
    j = merge_json_tail(        sg , j );
    
    j = merge_json_player_list( sg , j );

    std::cout << j.dump(4) << std::endl;

/*
    j = merge_json_colony_list( sg , j );
    j = merge_json_unit_list(   sg , j );
    j = merge_json_nation_list( sg , j );
    j = merge_json_tribe_list(  sg , j );
    j = merge_json_indian_list( sg , j );
    j = merge_json_map(         sg , j );

    std::cout << j.dump(4) << std::endl;
*/

}


$all_functions

json json_base() {
    auto j = R"(
$json
    )"_json;
    return j;
}
ENDTEXT

exit;

sub set_data {
    my ( $hash, $bytes, $hints, @id ) = @_;
    my $last   = pop @id;
    my $so_far = '';
    foreach my $part (@id) {
        $so_far .= '.' if $so_far;
        $so_far .= $part;
        $hash->{$part} //= {};
        $hash = $hash->{$part};
    }
    my $exists = $hash->{$last};
    die "$so_far.$last already exists: " . Dumper($exists) if $exists;
    $ORDER++;

 #print "Setting $so_far.$last, order=$ORDER bytes=$bytes hints=$hints\n";
    $hash->{$last} = {
        order   => $ORDER,
        bytes   => $bytes,
        hints => $hints,
    };
}

sub get_struct {
    my ($line)   = @_;
    my $match    = '.*struct\s+(\S+)\s+\{.*';
    my ($struct) = ( $line =~ m/$match/ );
    return $struct;
}

sub get_chunk {
    my ($line) = @_;
    my $chunk_match = '(char|u?int\d+_t)';
    my ( $chunk, $name, $suffix, $hints )
        = ( $line =~ m/$chunk_match\s+([a-z_0-9A-Z]+)\D*(\d+\D*)?;(.*)/ );
    $suffix =~ s/\D//g if $suffix;
    return ( $chunk, $name, $suffix, $hints );
}

sub get_bytes {
    my ( $chunk, $suffix ) = @_;
    my ($base) = ( $chunk =~ m/(\d+)/ );
    if ($base) {
        $base = $base / 8;
    }
    else {
        $base = 1;
    }
    $suffix //= 1;

    #print "base=$base suffix=$suffix\n";
    return $base * $suffix;
}

sub is_return {
    my ($line) = @_;
    my $match = '__attribute__ ((packed))';
    return ( $line =~ m/\Q$match\E/ ) ? 1 : 0;
}

sub simplify_map {
    my ($content) = @_;
    my $start     = 'struct map {';
    my $end       = '} __attribute__ ((packed)) map;';
    my $replace   = 'uint8_t map[4176];';
    $content =~ s/\Q$start\E[\s\S]*\Q$end\E/$replace/;
    die "Unable to simplify map section!" if $content !~ m/\Q$replace\E/;
    return $content;
}

__DATA__
#include <stdint.h>
enum { DISCOVERER = 0, EXPLORER = 1, CONQUISTADOR = 2, GOVERNOR = 3, VICEROY = 4 } //36
head:
    9,string,sig_colonize
    3,byte,unknown
    2,number,map_size_x
    2,number,map_size_y
    1,byte,tut1.nr13
    1,byte,tut1.nr14
    1,byte,tut1.unk3
    1,byte,tut1.nr15
    1,byte,tut1.nr16
    1,byte,tut1.nr17
    1,byte,tut1.unk7
    1,byte,tut1.nr19
    1,byte,unk1
    14,byte,game_options.unknown7
    2,byte,game_options.tutorial_hints     
    2,byte,game_options.water_color_cycling
    2,byte,game_options.combat_analysis    
    2,byte,game_options.autosave           
    2,byte,game_options.end_of_turn        
    2,byte,game_options.fast_piece_slide   
    2,byte,game_options.unknown            
    2,byte,game_options.show_foreign_moves 
    2,byte,game_options.show_indian_moves  
    2,byte,colony_report_options.labels_on_cargo_and_terrain       
    2,byte,colony_report_options.labels_on_buildings               
    2,byte,colony_report_options.report_new_cargos_available       
    2,byte,colony_report_options.report_inefficient_government     
    2,byte,colony_report_options.report_tools_needed_for_production
    2,byte,colony_report_options.report_raw_materials_shortages    
    2,byte,colony_report_options.report_food_shortages             
    2,byte,colony_report_options.report_when_colonists_trained     
    2,byte,colony_report_options.report_sons_of_liberty_membership 
    2,byte,colony_report_options.report_rebel_majorities           
    12,byte,colony_report_options.unused
    1,byte,tut2.howtowin        
    1,byte,tut2.background_music
    1,byte,tut2.event_music     
    1,byte,tut2.sound_effects   
    1,byte,tut2.nr1
    1,byte,tut2.nr2
    1,byte,tut2.nr3
    1,byte,tut2.nr4
    1,byte,tut3.nr5
    1,byte,tut3.nr6
    1,byte,tut3.nr7
    1,byte,tut3.nr8
    1,byte,tut3.nr9
    1,byte,tut3.nr10
    1,byte,tut3.nr11
    1,byte,tut3.nr12
    2,numbers00
    2,year
    2,autumn
    2,turn
    2,numbers01
    2,active_unit
    6,numbers02
    2,tribe_count
    2,unit_count
    2,colony_count
    6,numbers03
    1,difficulty
    2, numbers04
    25,founding_father
    6,numbers05
    8,nation_relation
    10,numbers06
    8,expeditionary_force
    8,numbers07
    32,count_down
    2,discovery_of_the_new_world    
    2,building_a_colony             
    2,meeting_the_natives           
    2,the_aztec_empire              
    2,the_inca_nation               
    2,discovery_of_the_pacific_ocean
    2,entering_indian_village       
    2,the_fountain_of_youth         
    2,cargo_from_the_new_world      
    2,meeting_fellow_europeans      
    2,colony_burning                
    2,colony_destroyed              
    2,indian_raid                   
    2,woodcut14                     
    2,woodcut15                     
    2,woodcut16                     
    2,unkb

player x 4:
    24,string,name
    24,string,country
    1,unk00
    1,control enum { PLAYER = 0, AI = 1 }
    1,founded_colonies
    1,diplomacy

24,byte,other.unkXX_xx

colony x head.colony_count:
    1,x_coord,x
    1,y_coord,y
    24,string,name
    1,nation
    4,unk0
    1,population
    32,byte,occupation
    32,profession
    16,unk6
    8,tiles,represents tiles around the colony. idx to citizen.
    12,unk8
    12,buildings.stockade : 3
    12,buildings.armory : 3
    12,buildings.docks : 3
    12,buildings.town_hall : 3
    12,buildings.schoolhouse : 3
    8,buildings.warehouse : 2
    4,buildings.stables : 1
    4,buildings.custom_house : 1
    8,buildings.printing_press : 2
    12,buildings.weavers_house : 3
    12,buildings.tobacconists_house : 3
    12,buildings.rum_distillers_house : 3
    8,buildings.capitol,not really in use
    6,buildings.fur_traders_house
    4,buildings.carpenters_shop
    4,buildings.church
    6,buildings.blacksmiths_house
    12,buildings.unused
    2,custom_house.food
    2,custom_house.sugar
    2,custom_house.tobacco
    2,custom_house.cotton
    2,custom_house.furs
    2,custom_house.lumber
    2,custom_house.ore
    2,custom_house.silver
    2,custom_house.horses
    2,custom_house.rum
    2,custom_house.cigars
    2,custom_house.cloth
    2,custom_house.coats
    2,custom_house.trade_goods
    2,custom_house.tools
    2,custom_house.muskets
    6,unka
    2,hammers
    1,building_in_production
    5,unkb
    32,stock
    8,unkd
    4,rebel_dividend
    4,rebel_divisor

unit x head.unit_count:
    1,x, y
    1,type
    4,owner,likely to be owner of unit, eng, fra, spa, dut, indian tribes, etc.
    4,unk04
    1,unk05
    1,moves,Accumulated moves (3 between land, 1 on roads, etc.)
    1,unk06
    1,unk07
    1,order, enum { PLOW = 8, ROAD = 9 }
    3,unk08
    1,holds_occupied
    4,cargo_item_0
    4,cargo_item_1
    4,cargo_item_2
    4,cargo_item_3
    4,cargo_item_4
    4,cargo_item_5
    6,cargo_hold
    1,turns_worked
    1,profession
    2,transport_chain.next_unit_idx
    2,transport_chain.prev_unit_idx,index to unit being transported? (treasure)

nation x 4:
    1,unk0
    1,tax_rate
    3,recruit
    1,unk1
    1,recruit_count,recruit penalty 120 + (count * 20) (does not go above 180)
    5,unk2
    2,liberty_bells_total
    2,liberty_bells_last_turn
    2,unk3
    2,next_founding_father
    2,founding_father_count
    2,ffc_high,suspect founding_father_count is 32bit.
    1,villages_burned
    5,unk4
    2,artillery_count,artillery purchased in europe. 500 + (count * 100) price penalty.
    2,boycott_bitmap
    8,unk5
    4,gold
    2,crosses
    12,unk6
    8,indian_relation,enum { NOT_MET = 0x00, WAR = 0x20, PEACE = 0x60}
    12,unk7
    16,trade.euro_price
    32,trade.nr
    64,trade.gold
    64,trade.tons
    64,trade.tons2

tribe x head.tribe_count:
    1,x, y
    1,nation
    1,state.artillery,artillery has been nearby?
    1,state.learned,visited and learned skill
    1,state.capital
    1,state.scouted,visited by scout
    1,state.unk5
    1,state.unk6
    1,state.unk7
    1,state.unk8
    1,population
    1,mission,ff if none 0 1 2 3 = eng fra spa dut
    4,unk1
    1,panic
    6,unk2
    1,population_loss_in_current_turn,due to attacks

58,byte,indian_relations.unk0
4,byte,indian_relations.meeting
8,indian_relations.unk1
1,indian_relations.aggr.aggr0
1,indian_relations.aggr.aggr0_high
1,indian_relations.aggr.aggr1
1,indian_relations.aggr.aggr1_high
1,indian_relations.aggr.aggr2
1,indian_relations.aggr.aggr2_high
1,indian_relations.aggr.aggr3
1,indian_relations.aggr.aggr3_high
15,stuff.unk15
2,stuff.counter_decreasing_on_new_colony
2,stuff.unk_short
2,stuff.counter_increasing_on_new_colony
696,stuff.unk_big
2,stuff.x
2,stuff.y
1,stuff.zoom_level
1,stuff.unk7
2,stuff.viewport_x
2,stuff.viewport_y
4176,byte,map
1502,tail.unk
