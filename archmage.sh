#!/bin/bash

build_dir=build
bin_dir=bin
examples_dir=examples
scripts_dir=scripts

#Setup for the scmod directories
mkdir -p ${build_dir}
mkdir -p ${bin_dir}

#Setup for the examples
for entry in ${examples_dir}/*
do
  mkdir -p ${examples_dir}/${entry}/${build_dir}
  mkdir -p ${examples_dir}/${entry}/${bin_dir}
done

#Permission modifiction for other scripts
sudo chmod u+x ${scripts}/*

#Installation of SCMOD
cd ${build_dir}
cmake ..
make install
rm -f scmod

echo "Setup of SCMOD complete. Ready to run."
