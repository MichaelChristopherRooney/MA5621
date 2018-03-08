#!/bin/bash

start=40000
end=42000

# Use seq to get the sequence of numbers to test.
# Only need to check up to sqrt(num).
# is_prime is set to 1 on each iteration of the outer loop, and is set to 0 if not prime.
# bc is used to do the maths operations
for num in $(seq $start 1 $end); do
	sqrt=`echo "sqrt($num)" | bc`
	is_prime=1 
	for div in $(seq 2 1 $sqrt); do
		res=$(( num % div ))
		if [ $res -eq 0 ]; then
			is_prime=0
			break
		fi
	done
	if [ $is_prime -eq 1 ]; then
		echo "$num is prime"
	fi
done
