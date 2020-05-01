#! /bin/bash

rm -rf *.o
gcc -c *.c
gcc -o .bin/a.out *.o 
rm -rf *.o
./.bin/a.out