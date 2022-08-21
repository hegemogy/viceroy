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
    my $close   = '} __attribute__ ((packed)) savegame;';
    $content =~ s/[\s\S]+struct savegame \{.*([\s\S]+)\Q$close\E[\s\S]+/$1/;

    @lines = grep m/\S/, split "\n", $content;
}
my @id = ();
my %DATA;
my %ITERATIONS;
my $ORDER;
foreach my $line (@lines) {

    # skip comments
    if ( $line =~ m|^\s*//.*| ) {
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
        $hints =~ s/\n//g;
        $hints =~ s/(\/\/|\/\*|\*\/)//g;
        $hints =~ s/^\s+//g;
        $hints =~ s/\s+$//g;
        set_data( \%DATA, $bits, $hints, @id, $name );
        next;
    }
    my $iterations = get_iterations($line);
    if ($iterations) {
        my $id = pop @id;
        die "Can't set iterations for '$id' because it is not unique!"
            if defined $ITERATIONS{$id};
        $ITERATIONS{$id} = $iterations;
        next;
    }

    # skip unnamed structs/unions, openings and closings
    if (   $line =~ m/(union|struct) \{/
        || $line =~ m/\Q__attribute__ ((packed));\E/ )
    {
        next;
    }
    die "DATA: "

        #. Dumper( \%DATA )
        . "line[$line] id[$id_string]\nERROR: Could not auto-generate from this line!";
}

#die Dumper( %ITERATIONS );
#die Dumper( $DATA{map} );
sub drill {
    my ( $data, @keys ) = @_;
    my @return;
    if ( $data->{bits} ) {
        $data->{keys} = \@keys;
        push @return, $data;
    }
    else {
        foreach my $key ( keys %{$data} ) {
            push @return, drill( $data->{$key}, @keys, $key );
        }
    }
    return @return;
}
use Storable qw(dclone);

sub printer {
    my ( $line, $style ) = @_;
    die "Expects a line and a style!" if !$line || !$style;
    my ( $keys, $hints, $order, $bits )
        = map { $line->{$_} // die "expected \$line->$_!" } 'keys', 'hints',
        'order', 'bits';
    my ( $type, $array_items, $total )
        = map { $bits->{$_} // die "expected \$line->bits->$_!" } 'type',
        'array_items', 'total';
    if ( $style eq 'standard' ) {
        my $label;
        foreach my $key ( @{$keys} ) {
            $label = join '.', grep {defined} $label, $key;
            my $iterations = $ITERATIONS{$key};
            $label .= "[$iterations]" if $iterations && $iterations ne '1';
        }
        $label .= "[$array_items]" if $array_items > 1;

        print "[$order] $label $type ($total) $hints\n";
    }
    elsif ( $style eq 'map' ) {
        if ( $keys->[0] eq 'map' ) {
            my $digits      = $total > 4 ? '02'        : '';
            my $description = $hints     ? " ($hints)" : '';
            my ( $map, $layer, $last ) = @{$keys};
            print
                "printf(\"map.$layer.%d.%d.$last=%${digits}x$description\\n\",x,y,map->$layer\[x+y*58].$last);\n";
        }
    }
    else {
        die "Style '$style' not supported!";
    }
}
my @drilled = drill( dclone \%DATA );

#printer($_) foreach sort { $a->{order} <=> $b->{order} } @drilled;

sub set_json {
    my ( $bits, @keys ) = @_;

    my $key_string = join '.', @keys;
    my $value      = "$key_string";

    my ( $total, $type, $items )
        = map { $bits->{$_} // die "Expected '$_'!" } 'total', 'type',
        'array_items';

    my @lines;
    if ( $items > 1 ) {
        my $iterator = ( scalar @keys == 1 ) ? 'i' : 'j';
        push @lines, "$value\[$iterator]";
        if ( $value =~ m/name$/ ) {
            push @lines, "$value";
        }
    }
    else {
        push @lines, $value;
    }
    return @lines;
}

sub set_json_section {
    my ( $data, $section ) = @_;
    my @lines;
    my $base      = $data->{$section};
    my $base_bits = $base->{bits};
    if ($base_bits) {
        push @lines, set_json( $base_bits, $section );
    }
    else {
        foreach my $key ( sort keys %{ $data->{$section} } ) {
            die Dumper( $data->{$section} ) if $key eq 'bits';
            my $value = $data->{$section}->{$key};
            my $bits  = $value->{bits};
            if ($bits) {
                push @lines, set_json( $bits, $section, $key );
            }
            else {
                foreach my $sub_key ( sort keys %{$value} ) {
                    die Dumper( $value, $sub_key ) if !ref $value->{$sub_key};
                    my $sub_value = $value->{$sub_key};
                    my $sub_bits  = $sub_value->{bits};
                    if ($sub_bits) {
                        push @lines,
                            set_json( $sub_bits, $section, $key, $sub_key );
                    }
                    else {
                        print "RECURSE key=$key sub_key=$sub_key subvalue="
                            . Dumper($sub_value);
                    }
                }
            }
        }
    }
    return @lines;
}

sub render_merge_function {
    my ( $data, $section ) = @_;
    my @lines = set_json_section( $data, $section );
    my @return;
    foreach my $line (@lines) {
        if ( $line =~ m/^map\./ ) {
            next if $line =~ m/base/;    # we do this one manually
            my @parts = split m/\./, $line;
            my $last  = pop @parts;
            $line = join '.', @parts;
            $line .= "[i][j].$last";
        }
        push @return, $line;
    }
    return @return;
}

sub render_merge_list_function {
    my ( $data, $section ) = @_;
    my @lines = set_json_section( $data, $section );
    my @loop_lines;
    foreach my $line (@lines) {
        $line =~ s/$section\./$section\[i\]./g;
        push @loop_lines, $line;
    }
    return @loop_lines;
}

sub render_if_block {
    my ($key) = @_;
    my $label = $key;
    $label =~ s/[\[\]]/./g;
    $label =~ s/\.+/./g;
    $label =~ s/\.$//g;
    $key   =~ s/i\]\[j/i+j*58/;
    my $prefix = "(input.compare(\"$label\") == 0) {";
    my $suffix = ( $label =~ m/name$/ )
        ? <<ENDTEXT
for(int k=0;k<23;k++){
${INDENT}${INDENT}${INDENT}sg->$key\[k]=name_value[k];
${INDENT}${INDENT}}
${INDENT}${INDENT}sg->$key\[23]=0;
ENDTEXT
        : "sg->$key = int_value;\n";
    return $prefix . "\n" . ( $INDENT x 2 ) . $suffix;
}

my $all_functions = join "${INDENT}}\n${INDENT}else if ",
    map { render_if_block($_) } (
    map { render_merge_function( \%DATA, $_ ) } (),

    'head', 'other', 'stuff', 'tail',
    'map'
    ),
    (
    map { render_merge_list_function( \%DATA, $_ ) } (),

    'player', 'nation', 'indian', 'colony', 'unit', 'tribe',
    );

path('./savegame_api.h')->spew(<<ENDTEXT);
#include <iostream>
#include <string>
#include <stdio.h>
#include <savegame.h>

void set_value( struct savegame *sg, std::string input, std::string value, int i, int j) {
    char name_value[24];
    int int_value;
    //printf("input=%s value=%s found=%ld\\n",input.c_str(),value.c_str(),value.find("name"));
    if (input.find("name") != std::string::npos && j < 0 ) {
        strcpy(name_value,value.substr(0,23).c_str());
        //printf("value=%s name_value=%s\\n",value.c_str(),name_value);
    }
    else {
        int_value = atoi(value.c_str());
    }

    if $all_functions
    }
    else if (input.compare("map.tile.i.j.base") == 0 ) {
        std::map<std::string, int>::iterator base = terrain_id.find(value);
        if (base != terrain_id.end()) {
            sg->map.tile[i+j*58].base = terrain_id[value];
            sg->map.tile[i+j*58].special = 0;
        }
        else {
            base = special_id.find(value);
            if (base != special_id.end()) {
                sg->map.tile[i+j*58].base = special_id[value];
                sg->map.tile[i+j*58].forest = 1;
                sg->map.tile[i+j*58].special = 1;
            }
            else {
                fprintf(stderr,"'%s' is not a valid terrain!",value.c_str());
                exit(EXIT_FAILURE);
            }
        }
	}
    else
        fprintf(stderr,"Did not find '%s'!\\n",input.c_str());
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
        order => $ORDER,
        bits  => $bits,
        hints => $hints,
    };
}

sub get_struct {
    my ($line) = @_;
    my $match = '.*(struct|union)\s+(\S+)\s+\{.*';
    my ( $type, $name ) = ( $line =~ m/$match/ );
    return $name;
}

sub get_chunk {
    my ($line) = @_;
    my $chunk_match = '(char|u?int\d+_t)';
    my ( $chunk, $name, $suffix, $hints )
        = (
        $line =~ m/$chunk_match\s+([a-z_0-9A-Z]+)\s*([:\[ \d]+)?\D*?;(.*)/ );
    return ( $chunk, $name, $suffix, $hints );
}

sub get_bits {
    my ( $type, $suffix ) = @_;
    my ($total) = ( $type =~ m/(\d+)/ );
    $total //= 8;    # e.g. char

    my $array_items = 0;
    if ($suffix) {
        my ($digits) = ( $suffix =~ m/(\d+)/ );
        if ( $suffix =~ m/\[/ ) {
            $array_items = $digits;
            $total       = $total * $array_items;
        }
        elsif ( $suffix =~ m/:/ ) {
            $total = $digits;    # bitwise (less than 8)
        }
        else {
            die "Unable to parse suffix=$suffix for type=$type!";
        }
    }
    return {
        type        => $type,
        total       => $total,
        array_items => $array_items,
    };
}

sub get_iterations {
    my ($line) = @_;
    my $match = '__attribute__ ((packed))';
    my ( $infinite, $name, $items )
        = ( $line =~ m/\Q$match\E (\*)?([a-z0-9_]+)\[?([0-9\*]+)?\]?;/ );
    return $infinite // $items // ( $name ? 1 : 0 );
}
