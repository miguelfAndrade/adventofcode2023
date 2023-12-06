#!/bin/bash

folder=$1
part=$2

cd $folder
if [ "$part" = "1" ];
then
    g++ main.cpp -o main.o
    ./main.o
elif [ "$part" = "2" ];
then
    g++ mainpt2.cpp -o main.o
    ./main.o
else
    echo ""
    echo "Wrong input!"  
    echo "--- sh run.sh 'Folder Day' 'Part of the challenge (1 or 2)' ---"
    echo "Example: sh run.sh day1 2"
    echo ""
fi
