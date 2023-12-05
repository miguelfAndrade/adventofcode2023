#!/bin/bash

cd $1
g++ -std=c++0x main.cpp -o main.o
./main.o