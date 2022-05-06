#!/usr/bin/env bash

COMPILER=`type -p gcc`

echo \*\*

if [ -x ${COMPILER} ]; then
	gcc  parse.c -o parse
else
	echo \*\* Cannot find compiler: ${COMPILER}
	exit 1
fi

if [ -x ./parse ]; then
	./parse > out.csv
else
	touch out.csv
fi

cmp -s out.csv validate.csv

if [ $? -eq 0 ]; then
	echo \*\* Your code passed with flying colors!
else
	echo \*\* Sorry, but your code did not produce the correct data file
fi

echo \*\*


