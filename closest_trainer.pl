#!/bin/env perl
use strict;
use warnings;
use Path::Tiny qw(path);
use Data::Dumper;
use JSON;
use List::Util qw(min sum);

my ($id,$x1,$y1) = @ARGV;
die "Need Col94 Save ID!" if !$id || $id !~ m/^[0-9]$/;
die "Need current X and Y!" if 2 != grep { $_ && $_ =~ m/^\d+$/} $x1,$y1;
my $got = `./savegame "/mnt/c/Program Files (x86)/GOG Galaxy/Games/Colonization/cloud_saves/MPS/COLONIZE/COLONY0$id.SAV" -t`;
my @lines = split "\n", $got; 
my @found;
# [  0] ( 12,  54): 10 Aztec       : state: artillery(0) learned(1) capital(1) scouted(1) 0 0 0 0, mission(-1) 00 ff ff ff panic( 0) 00 00 00 00 00 00 00
foreach my $line (@lines) {
    next if $line =~ m/-- tribes --/;
    my ($x2,$y2,$learned) = ($line =~ m/[^(]+\(\D*(\d+)\D+(\d+).*learned\((\d)/);
    die "Bad parse line=[$line]!" if 3 != grep {defined} $x2,$y2,$learned;
    print "x2=$x2 y2=$y2 learned=$learned\n";
    next if $learned;
    my $x_delta = abs($x1 - $x2);
    my $y_delta = abs($y1 - $y2);
    my $diagonal = min($x_delta,$y_delta);
    my $distance = sum($x_delta,$y_delta,-$diagonal);
    push @found , {
        distance => $distance,
        line => $line,
    };
}
my @sorted = sort {$a->{distance}<=>$b->{distance}} @found;
print $_->{distance}.' '.$_->{line}."\n" foreach @sorted;
