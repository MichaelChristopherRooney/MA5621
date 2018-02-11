#!/bin/bash

declare -a ROUND_ARGS=("1000" "1024" "1100" "-M 100000" "-M 1048576" "-M 10485760" "-M 104857600" "-G 1073741824" "-T 1099511627776" "-P 1125899906842624" "-E 1152921504606846976" "-h 11529215046")
declare -a ROUND_RESULTS=("1000 = 1.0K" "1024 = 1.0K" "1100 = 1.1K" "100000 = 0.1M" "1048576 = 1.0M" "10485760 = 10.0M" "104857600 = 100.0M" "1073741824 = 1.0G" "1099511627776 = 1.0T" "1125899906842624 = 1.0P" "1152921504606846976 = 1.0E" "11529215046 = 10.7G")

for value in {0..11}
do
	round_result=$(./round ${ROUND_ARGS[value]})
	if [ "$round_result" == "${ROUND_RESULTS[value]}" ]; then
		echo "Test passed: $round_result"
	else
		echo "Test failed: expected ${ROUND_RESULTS[value]} but got $round_result"
	fi
done
