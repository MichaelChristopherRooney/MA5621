#!/bin/bash

if [ "$#" -ne 3 ]; then
	echo "ERROR: expected 3 paramaters"
	exit	
fi

a=$1
b=$2
c=$3

# This is everything under the square root
part_1=`echo "($b * $b) - (4 * $a * $c)" | bc -l`

# Check if number is negative by looking for "-" as the first character.
if [ "${part_1:0:1}" = "-" ]; then
	echo "ERROR: part under square root cannot be negative"
	exit
fi

part_2=`echo "sqrt($part_1)" | bc -l`

# This is ((-b) + part_1) / 2a
root_1=`echo "(($b * -1) + $part_2) / (2*$a)" | bc -l`

# This is ((-b) - part_1) / 2a
root_2=`echo "(($b * -1) - $part_2) / (2*$a)" | bc -l`

echo "Root one: $root_1"
echo "Root two: $root_2"
