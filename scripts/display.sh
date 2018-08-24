#!/bin/bash

example_dir../examples/$1/resources/output
solutions=solution
grids=grid

cd ${example_dir}

echo "   These are the possible results:"

for entry in ${example_dir}
do
  echo "     *" ${entry}
done

echo "    Which would you like to view?"

read varname

for entry in ${example_dir}
do
  if [[ ${varname} == ${entry} ]]; then
    echo "    Opening..."
    open ${varname}
  else
    echo "    Not a valid filehandle."
    echo "    Please select a valid filehandle for viewing."
  fi
done
