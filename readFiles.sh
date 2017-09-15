#!/bin/bash
# This scritp show files into a ASCII model from JSON files 
#
# File to organize files into temporary collection into acervo directory
if [ $# -lt 1 ] ; then
	echo -e "ERRO $#\nSintax: $0 file\n(file must be in the data directory)"
	exit
fi
# Verify if file exists
if [ -f data/$1 ] ; then
	./app/splitJsonFiles $1
fi

# read string and change UTF-8 to ASCII
for files in `ls acervo`
	do
	x=`awk -F"\"" '{ print $14 }' acervo/$files`
	echo -e $x >collection/$files
	done
rm acervo/*

