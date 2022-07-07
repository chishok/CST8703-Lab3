#!/usr/bin/env bash

TARGET_NAME=CST8703Lab3-FeasibleWorkload
SUBFOLDER=FeasibleWorkload

rm -rf ./build
cmake -DCMAKE_INSTALL_PREFIX=${HOME}/.local -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -S. -B./build
cmake --build ./build --target ${TARGET_NAME} -j 4 --

./build/${SUBFOLDER}/${TARGET_NAME} |& tee output.txt
