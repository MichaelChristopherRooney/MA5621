#!/bin/bash

declare -a SEQ_ARGS=("3" "0 3" "0 2 10" "1 2 10" "0 2 10 -w" "" "-w")
# Note: need trailing space on each result
declare -a SEQ_RESULTS=("1 2 3 " "0 1 2 3 " "0 2 4 6 8 10 " "1 3 5 7 9 " "00 02 04 06 08 10 " "ERROR: too few arguments passed " "ERROR: too few arguments passed ")

for value in {0..6}
do
	seq_result=$(./my_seq ${SEQ_ARGS[value]})
	# Output includes newlines so we replace them with spaces
	seq_result=$(echo $seq_result | tr '\n' ' ')
	if [ "$seq_result" == "${SEQ_RESULTS[value]}" ]; then
		echo "Test passed: $seq_result"
	else
		echo "Test failed: expected ${SEQ_RESULTS[value]} but got $seq_result"
	fi
done
