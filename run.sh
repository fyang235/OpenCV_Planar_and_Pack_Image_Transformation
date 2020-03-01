#!/bin/bash

rm -rf build
mkdir build
cd build

cmake ..
make
cd ..

./build/PLANAR2JPG