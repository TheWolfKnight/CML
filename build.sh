#!/bin/bash

FLAGS="-Wall -g"
TARG="-o bin/debug/main.o"
COMP="src/main.c src/fs/fs.c src/String/String.c"

gcc $FLAGS $TARG $COMP
