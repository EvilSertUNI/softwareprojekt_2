#!/bin/sh

cmake -G "Unix Makefiles" -S . -B build -D CMAKE_C_COMPILER=gcc -DCMAKE_BUILD_TYPE=Release
cd build
make ${1+"$@"}



