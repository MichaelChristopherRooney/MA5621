#!/bin/bash

# Validate paramater was provided
if [ "$#" -ne 1 ]; then
	echo "ERROR: expected only filename passed as parameter"
	exit	
fi

filename=$1

# Validate file exists
if [ ! -f $filename ]; then
	echo "ERROR: $filename does not exist"
	exit
fi

# Compress with all required programs
zip ${filename}.zip $filename -q
gzip $filename -c > ${filename}.gz -q
bzip2 $filename -c > ${filename}.bz2 -q
xz -c $filename > ${filename}.xz -q

# Get sizes of original and compressed versions
orig_size=`du -b "$filename" | cut -f1`
zip_size=`du -b "${filename}.zip" | cut -f1`
gz_size=`du -b "${filename}.gz" | cut -f1`
bz2_size=`du -b "${filename}.bz2" | cut -f1`
xz_size=`du -b "${filename}.xz" | cut -f1`

# Calulcate compression ratios
zip_ratio=$(( (zip_size*100) / orig_size ))
gz_ratio=$(( (gz_size*100) / orig_size ))
bz2_ratio=$(( (bz2_size*100) / orig_size ))
xz_ratio=$(( (xz_size*100) / orig_size ))

echo -e "Original size:\t$orig_size bytes"
echo -e "zip size:\t$zip_size bytes (${zip_ratio}%)"
echo -e "gz size:\t$gz_size bytes (${gz_ratio}%)"
echo -e "bz2 size:\t$bz2_size bytes (${bz2_ratio}%)"
echo -e "xz size:\t$xz_size bytes (${xz_ratio}%)"

# Cleanup
rm ${filename}.zip
rm ${filename}.gz
rm ${filename}.bz2
rm ${filename}.xz


