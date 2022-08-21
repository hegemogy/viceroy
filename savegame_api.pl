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
my @RESERVED = ( 'keys', 'hints', 'order', 'data_type', 'items', 'total' );
my %RESERVED = ( map { $_ => 1 } @RESERVED );
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
    my ( $type, $name, $suffix, $hints ) = get_chunk($line);
    if ($type) {
        my ( $total, $items ) = get_bits( $type, $suffix );
        $hints =~ s/\n//g;
        $hints =~ s/(\/\/|\/\*|\*\/)//g;
        $hints =~ s/^\s+//g;
        $hints =~ s/\s+$//g;
        set_data( \%DATA, $type, $total, $items, $hints, @id, $name );
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
    die "PARSE ERROR: line[$line] id[$id_string]\n";
}

#die Dumper( %ITERATIONS );
#die Dumper( $DATA{map} );
sub drill {
    my ( $data, @keys ) = @_;
    my @return;
    if ( $data->{order} ) {
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
    die Dumper($line) if $line->{keys}->[-1] eq 'nation';
    die "Expects a line and a style!" if !$line || !$style;
    my ( $keys, $hints, $order, $type, $items, $total )
        = map { $line->{$_} // die "expected \$line->$_! " . Dumper($line) }
        @RESERVED;
    my $label;
    foreach my $key ( @{$keys} ) {
        $label = join '.', grep {defined} $label, $key;
        my $iterations = $ITERATIONS{$key};
        $label .= "[$iterations]" if $iterations && $iterations ne '1';
    }
    $label .= "[$items]" if $items > 1;

    my $set_label = $label;
    $set_label =~ s/\*/][/;
    $set_label =~ s/(\[\d+|\[\]\[)/[i/;
    $set_label =~ s/\d+\]/j]/;

    my $set_key = $set_label;
    $set_key =~ s/i\]\[j/i+j*58/;
    $set_key = "sg->$set_key";

    my @return;
    if ( $style eq 'standard' ) {
        push @return, "[$order] $label $type ($total) $hints\n";
    }
    elsif ( $style eq 'map' ) {
        if ( $keys->[0] eq 'map' ) {
            my $digits      = $total > 4 ? '02'        : '';
            my $description = $hints     ? " ($hints)" : '';
            my ( $map, $layer, $last ) = @{$keys};
            push @return,
                "printf(\"map.$layer.%d.%d.$last=%${digits}x$description\\n\",x,y,map->$layer\[x+y*58].$last);\n";
        }
    }
    elsif ( $style eq 'if_block' ) {
        $set_label =~ s/[\[\]]/./g;
        $set_label =~ s/\.+/./g;
        $set_label =~ s/\.$//g;
        push @return, <<ENDTEXT;
if (input.compare(\"$set_label\") == 0) {
        $set_key = int_value;
ENDTEXT
        if ( $type eq 'char' ) {
            $set_label =~ s/\.\D$//;
            $set_key   =~ s/\[\D\]$//;
            push @return, <<ENDTEXT;
if (input.compare(\"$set_label\") == 0) {
        strcpy($set_key,value.substr(0,$items).c_str());
ENDTEXT
        }
    }
    else {
        die "Style '$style' not supported!";
    }
    return @return;
}
my @drilled   = drill( dclone \%DATA );
my $if_blocks = join "${INDENT}}\n${INDENT}else ",
    map  { printer( dclone $_, 'if_block' ) }
    sort { $a->{order} <=> $b->{order} }
    grep { $_->{keys}->[-1] ne 'base' } @drilled;

path('./savegame_api.h')->spew(<<ENDTEXT);
#include <iostream>
#include <string>
#include <stdio.h>
#include <savegame.h>

void set_value( struct savegame *sg, std::string input, std::string value, int i, int j) {
    int int_value = atoi(value.c_str());
    
    $if_blocks
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
    my ( $hash, $type, $total, $items, $hints, @id ) = @_;
    die "$_ is reserved!" foreach grep { $RESERVED{$_} } @id;
    my $last = pop @id;
    foreach my $part (@id) {
        $hash->{$part} //= {};
        $hash = $hash->{$part};
    }
    my $exists = $hash->{$last};
    die "" . ( join '.', @id, $last ) . " already exists: " . Dumper($exists)
        if $exists;
    $ORDER++;

    #print "Setting $so_far.$last, order=$ORDER bytes=$bytes hints=$hints\n";
    $hash->{$last} = {
        keys      => \@id,
        order     => $ORDER,
        data_type => $type,
        items     => $items,
        total     => $total,
        hints     => $hints,
    };
    while ( my ( $key, $value ) = each %{ $hash->{$last} } ) {
        die "'$key' is a reference!" . Dumper( $key, $value )
            if ref $value && $key ne 'keys';
    }
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

    my $items = 0;
    if ($suffix) {
        my ($digits) = ( $suffix =~ m/(\d+)/ );
        if ( $suffix =~ m/\[/ ) {
            $items = $digits;
            $total = $total * $items;
        }
        elsif ( $suffix =~ m/:/ ) {
            $total = $digits;    # bitwise (less than 8)
        }
        else {
            die "Unable to parse suffix=$suffix for type=$type!";
        }
    }
    return ( $total, $items );
}

sub get_iterations {
    my ($line) = @_;
    my $match = '__attribute__ ((packed))';
    my ( $infinite, $name, $items )
        = ( $line =~ m/\Q$match\E (\*)?([a-z0-9_]+)\[?([0-9\*]+)?\]?;/ );
    return $infinite // $items // ( $name ? 1 : 0 );
}
