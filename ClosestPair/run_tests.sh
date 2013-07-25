#!/bin/bash

g++ closest_pair.cpp -o closest_pair.out
rm -rf results.dat
for i in 10 100 1000 10000 100000 1000000
do
    ./closest_pair.out 2>> results.dat $i
done
