#!/bin/sh

#perl savegame_json_generator.pl || exit
aclocal $AL_OPTS
autoconf $AC_OPTS
autoheader $AH_OPTS
automake --add-missing --foreign
./configure
make
