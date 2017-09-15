#!/bin/bash

for files in `ls acervo`
	do
	x=`awk -F"\"" '{ print $14 }' acervo/$files`
	echo -e $x >collection/$files
	done
