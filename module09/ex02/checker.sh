#!/bin/bash

input=$(shuf -i 1-100000 -n 5000 | tr "\n" " ")
./PmergeMe $input | awk '/^After/ {for (i=3; i<=NF; i++) print $i}' > mySort
echo $input | tr " " "\n" | sort -n > realSort
if diff mySort realSort > /dev/null;
then
	echo "The output is correctly sorted."
else
	echo "The output is NOT sorted."
fi