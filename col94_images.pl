#!/bin/env perl
use strict;
use warnings;
use Path::Tiny qw(path);
my @all = path("images/surface/")->children;
foreach my $file (@all) {
    # images/surface/phys0.ss_0.png
    my ( $pre, $id ) = ( $file->basename =~ m/^(.*ss)_(\d+)\.png$/ );
    die "failed $file" if !defined $id;
    my $new = $file->parent->child( sprintf "%s.%03d.png", $pre, $id );
    $file->copy($new);
}
