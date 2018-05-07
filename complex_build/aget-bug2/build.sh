#!/bin/bash
./clean.sh
rm -Rf run
mkdir run
cd aget-devel
make
cp aget ../run
cp 0 ../run
cp 17573 ../run
cd ..

cp run.sh run
