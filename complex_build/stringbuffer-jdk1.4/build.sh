#!/bin/bash
./clean.sh
make && \
mkdir run && \
cp main run

cp run.sh run
