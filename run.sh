#!/bin/bash

rm -rf build
mkdir build
cd build

cmake ..
make
cd ..

./build/src/PLANAR2JPG