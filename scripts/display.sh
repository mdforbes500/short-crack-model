#!/bin/bash

example_dir=../examples/$1/resources/output

echo "   These are the possible results:"

for entry in ${example_dir}/*
do
  echo "     *" $(basename ${entry})
done

echo "    Which would you like to view?"

read varname

found=0

for entry in ${example_dir}/*
do
  if [[ ${example_dir}/${varname} == ${entry} ]]; then
    echo "    Opening..."
    open ${example_dir}/${varname}
    found=1
  fi
done

if [ ${found} -eq 0 ]; then
  echo "    Not a valid filehandle."
  echo "    Please select a valid filehandle for viewing."
fi
