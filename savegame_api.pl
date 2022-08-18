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
        my $bits = get_bits( $chunk, $suffix );
        if ($leading) {
            $hints = "$leading,$hints";
            $leading = '';
        }
        $hints =~ s/\n//g;
        set_data( \%DATA, $bits, $hints, @id, $name );
        next;
    }
    if ( is_return($line) ) {
        pop @id;
        next;
    }
    die "DATA: " . Dumper( \%DATA ) . "line[$line] id[$id_string]\nERROR: Could not auto-generate from this line!";
}

sub set_json {
    my ($bits,@keys)     = @_;
    
    my $key_string = join '.', @keys;
    my $value = "sg->$key_string";

    my ($total,$type,$items) = map {$bits->{$_}//die "Expected '$_'!"} 'total','type','array_items';
    
    my @lines;
    if ($items > 1) {
        die $value if $value =~ m/\[/;
        my $var = $value;
        $var =~ s/[^a-z0-9]/_/g;
        $var =~ s/^_*//g;
        $var =~ s/_*$//g;
        $var =~ s/__+/_/g;
        foreach my $index ( 0 .. ($items-1) ) {
            push @lines, "$value\[$index]";
        }
    }
    else {
        push @lines,$value;
    }
    return @lines;
}

sub set_json_section {
    my ( $data, $section, @parent_keys ) = @_;
    my @lines;
    foreach my $key (sort keys %{ $data->{$section} } ) {
        my $value = $data->{$section}->{$key};
        my $bits = $value->{bits};
        if ( $bits ) {
            push @lines, set_json($bits,$section,@parent_keys,$key );
        }
        else {
            foreach my $sub_key (sort keys %{$value} ) {
                my $sub_value = $value->{$sub_key};
                my $sub_bits = $sub_value->{bits};
                if ( $sub_bits ) {
                    push @lines, set_json( $sub_bits,$section, $key, $sub_key );
                }
                else {
                    print "RECURSE key=$key sub_key=$sub_key subvalue=".Dumper($sub_value);
                }
            }
        }
    }
    return @lines;
}

sub render_merge_function {
    my ( $data, $section ) = @_;
    my @lines        = set_json_section( $data, $section );
    return @lines;
}

#TODO j["player_list"][i]["nation"]["value"] = nation_list[i];
sub render_merge_list_function {
    my ( $data, $section ) = @_;
    my $section_list = $section."_list";
    my @lines        = set_json_section( $data, $section );
    my @loop_lines;
    foreach my $line (@lines) {
        $line =~ s/$section"]/$section_list"][i]/g;
        $line =~ s/$section\./$section\[i\]./g;
        push @loop_lines, $line;
    }
    return @loop_lines;
}

my $all_functions = join "\n${INDENT}else if ",
    map { 
("(input.compare(\"$_\") == 0)\n".($INDENT x 2)."$_ = new_value;")
    }
    (
    map { render_merge_function( \%DATA, $_ ) } (),
    'head', 'other',# 'stuff', 'tail'
    ),
    ( map { render_merge_list_function( \%DATA, $_ ) } (),
        #'player','nation','indian',
    'colony',
    #'unit',     'tribe', 
);
path('./savegame_api.h')->spew(<<ENDTEXT);
#include <iostream>
#include <string>
#include <stdio.h>
void set_value( struct savegame *sg, std::string input, int i, int new_value) {
    if $all_functions
    else
        fprintf(stderr,"Did not find '%s'!",input.c_str());
}
ENDTEXT
exit;

sub set_data {
    my ( $hash, $bits, $hints, @id ) = @_;
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
        bits   => $bits,
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
        = ( $line =~ m/$chunk_match\s+([a-z_0-9A-Z]+)\s*([:\[ \d]+)?\D*?;(.*)/ );
    return ( $chunk, $name, $suffix, $hints );
}

sub get_bits {
    my ( $type, $suffix ) = @_;
    my ($total) = ( $type =~ m/(\d+)/ );
    $total //= 8; # e.g. char

    my $array_items = 0;
    if ($suffix) {
        my ($digits) = ($suffix =~ m/(\d+)/);
        if ($suffix =~ m/\[/) {
            $array_items = $digits;
            $total = $total * $array_items;
        }
        elsif ( $suffix =~ m/:/ ){
            $total = $digits; # bitwise (less than 8)
        }
        else {
            die "Unable to parse suffix=$suffix for type=$type!";
        }
    }
    return {
        type => $type,
        total => $total,
        array_items => $array_items,
    };
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
