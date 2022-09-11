#!/bin/env perl
use strict;
use warnings;
use Path::Tiny qw(path);
die "USAGE: ./savegame_diff 2 3 -t" if !@ARGV;
my $binary = `which savegame` || './savegame';
die "Could not find savegmae binary!" if !-x $binary;
my $dir = '/mnt/c/Program Files (x86)/GOG Galaxy/Games/Colonization/cloud_saves/MPS/COLONIZE/';
die "Could not find savegame directory at $dir!" if !-d $dir;
my @options = @ARGV;
my %data;
my @items = qw(one two);
foreach my $name (@items) {
    $data{$name} = {
        file => "/tmp/$name",
        index => (shift @options),
    };
}
savegame($_,@options) foreach values %data;
my $files = join ' ', map {$data{$_}->{file}} @items;
my $diff = "git diff --word-diff --no-index $files";
`$diff > /dev/tty`;
`$diff` || print "No changes:\n$data{one}->{data}";

sub savegame {
    my ($hash,@options) = @_;
    my ($index,$file) = map{ $hash->{$_}//die "Expected '$_' key!"} 'index','file';
    die "Expected 0-9 index!" if $index !~ m/^\d$/;
    die "Expected options!" if !@options;
    my $options = join ' ',@options;
    my $command = "$binary -f '$dir/COLONY0$index.SAV' $options";
    my $result = `$command`;
    $hash->{data}=$result;
    path($file)->spew($result);
}
