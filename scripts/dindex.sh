#!/bin/bash

search_dir=../examples
write_path=../build
filename=examples_list

# Print input to console
# Input should be relative path to directory
echo "Searching examples directory for names of examples..."

# Remove file if it already exists
if [ -f ${write_path}/${filename}.txt ] ; then
  rm ${write_path}/${filename}.txt
fi

# Write entries to new file
for entry in ${search_dir}/*
do
  filehandle=$(basename ${entry})
  echo ${filehandle} >> ${write_path}/${filename}.txt
done

echo "List of examples generated."
