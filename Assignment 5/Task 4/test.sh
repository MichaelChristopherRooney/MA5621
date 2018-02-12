#!/bin/bash

expected_result=$"00000000  65 66 61 65 66 0a 65 66  09 71 66 65 71 65 66 71  |efaef.ef.qfeqefq|
00000010  0a 09 71 65 66 65 66 71  66 0a 66 61 0a           |..qefefqf.fa....|
0000001d"

hex_result=$(cat test.txt | ./my_hexdump)
# Output includes newlines so we replace them with spaces
#hex_result=$(echo $hex_result | tr '\n' ' ')
if [ "$hex_result" == "$expected_result" ]; then
	echo "Test passed: $hex_result"
else
	echo "Test failed."
	echo "Expected: $expected_result"
	echo "Got: $hex_result"
fi


