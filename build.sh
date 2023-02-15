#!/bin/bash

FLAGS="-Wall -g"
TARG="-o bin/debug/main.o"
COMP="src/main.c src/common.c src/fs/fs.c src/String/String.c src/parser/cml.c"

gcc $FLAGS $TARG $COMP
