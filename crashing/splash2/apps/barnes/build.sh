#! /bin/bash
./clean.sh
make && \
rm -Rf run && \
mkdir run && \
cp BARNES run
