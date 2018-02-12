#!/bin/bash

declare -a GREP_ARGS=("KEYWORD" "KEYWORD -n" "KEYWORD -v" "KEYWORD -c" "" "-n -v")
# Note: need trailing space on each result
declare -a GREP_RESULTS=("aaaKEYWORDbbb " "\x1B[32m1:\x1B[0maaaKEYWORDbbb " "cccdddeeefff " "aaa\x1B[31mKEYWORD\x1B[0mbbb " "ERROR: please provide a word to search for " "ERROR: please provide a word to search for ")

for value in {0..5}
do
	grep_result=$(cat test.txt | ./my_grep ${GREP_ARGS[value]})
	# Output includes newlines so we replace them with spaces
	grep_result=$(echo $grep_result | tr '\n' ' ')
	# Need this step to properly compare colours
	expected_result=$(echo -e "${GREP_RESULTS[value]}")
	if [ "$grep_result" == "$expected_result" ]; then
		echo "Test passed: $grep_result"
	else
		echo "Test failed: expected $expected_result but got $grep_result"
	fi
done
