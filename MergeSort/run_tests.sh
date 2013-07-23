#!/bin/bash

g++ mergesort.cpp -o mergesort.out
rm -rf results.dat
for i in 10 100 1000 10000 100000 1000000 10000000
do
    ./mergesort.out 2>> results.dat $i
done
