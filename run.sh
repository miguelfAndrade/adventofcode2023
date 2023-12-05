#!/bin/bash

path=$(pwd)
file="$path/$1/main.cpp"
g++ $file
./a.out