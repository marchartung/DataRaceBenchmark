#! /bin/bash

rm -r run
mkdir run
OUTDIR="`pwd`/run"

cd apps/barnes
./clean.sh
./build.sh
cp BARNES $OUTDIR
cd ../..

cd kernels
#cd fft
#./build.sh
#cd ..
cd lu/non_contiguous_blocks
./clean.sh
./build.sh
cp LU $OUTDIR
cd ../..
cd ..

cp run.sh run


