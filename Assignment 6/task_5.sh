#!/bin/bash

if [ "$#" -ne 1 ]; then
	echo "ERROR: expected only filename passed as parameter"
	exit	
fi

filename=$1

if [ ! -f $filename ]; then
	echo "ERROR: $filename does not exist"
	exit
fi

#zip hamlet.zip hamlet.txt
#gzip hamlet.txt -c > hamlet.gz
#bzip2 hamlet.txt -c > hamlet.bz2 
#xz -c hamlet.txt > hamlet.xz

