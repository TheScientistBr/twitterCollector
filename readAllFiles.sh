#!/bin/bash
# This scritp show files into a ASCII model from JSON files 
#
# File to organize files into temporary collection into acervo directory
# Verify if file exists

for file in  "enem-2015-06-30.json  enem-2015-07-05.json  enem-2015-07-10.json  enem-2015-07-15.json  enem-2015-07-20.json enem-2015-07-21.json"
	do
	if [ -f data/$file ] ; then
		./app/splitJsonFiles $file
	fi

	echo $file
	# read string and change UTF-8 to ASCII
	for files in `ls acervo`
		do
		x=`awk -F"\"" '{ print $14 }' acervo/$files`
		# compare files - must be uniq
		key_w=1
		for target in `ls collection`
			do
			y=`cat collection/$target`
			if [ "$x" == "$y" ] ; then
				key_w=0
				break
			fi
			done
		if [ $key_w -eq 1 ] ; then
			echo -e $x >collection/$files
		fi
		done
	rm acervo/*
	done

