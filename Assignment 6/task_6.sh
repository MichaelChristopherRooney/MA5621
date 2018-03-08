#!/bin/bash

# If a filepath with spaces is not escaped or enclosed with quotes we will have
# more than 1 parameter.
if [ "$#" -gt 1 ]; then
	echo "ERROR: Expecting only 0 or 1 parameters"
	echo "Did you forget to escape a filepath with spaces in it?"
	exit
fi

# Use parameter if provided, else use ./
# If paramater is provided ensure there is a "/" at the end.
# It does not matter if there already is a "/" and we append
if [ "$#" -ne 1 ]; then
	dir="./"
else
	dir="$1/"
fi

# Max depth = 0, don't search subdirectories
# stderr is silenced as find complained both when there is no *.sh files, or any non *.sh files
num_dir=`find "$dir"* -maxdepth 0 -type d | wc -l`
num_sh=`find "$dir"*.sh -maxdepth 0 -type f 2> /dev/null | wc -l`
num_other=`find "$dir"*[^.sh] -maxdepth 0 -type f 2> /dev/null | wc -l`

echo "Directory is $dir"
echo "There is $num_dir directories"
echo "There is $num_sh shell scripts"
echo "There is $num_other other files"
