#!/bin/bash

examples_dir=../examples
filename=$1
build_dir=build
binary_dir=bin

cd ../${examples_dir}/${filename}/${build_dir}
cmake ..
make install
cd ${examples_dir}/${filename}/${binary_dir}
./${filename}
