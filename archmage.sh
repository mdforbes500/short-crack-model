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
  mkdir -p ${entry}/${build_dir}
  mkdir -p ${entry}/${bin_dir}
done

#Permission modifiction for other scripts
sudo chmod u+x ${scripts}/*

#Installation of SCMOD
cd ${build_dir}
cmake ..
make install
rm -f scmod

#Setting up list of examples
cd ../${scripts_dir}
./dindex.sh

#Export PATH
cd ..
sudo echo $(pwd)/${bin_dir} >> sudo /etc/paths
echo "PATH set to " $(pwd)/${bin_dir}

echo "Setup of SCMOD complete. Ready to run."
echo "Type scmod --help for usage."
