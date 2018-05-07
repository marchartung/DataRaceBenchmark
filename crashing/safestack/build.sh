#!/bin/bash
./clean.sh
$CXX -std=c++0x -g -O0 -o main.x SafeStack.cpp -pthread && \
rm -Rf run && \
mkdir run && \
cp main.x run

cp run.sh run