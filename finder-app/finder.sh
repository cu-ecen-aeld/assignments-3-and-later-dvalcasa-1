#!/bin/sh
# Author: dvalcasa

if [ $# -lt 2 ]
then
	echo "need two arguments. first argument is a path to a directory and second is a text string"
	exit 1
fi

filesdir=$1
searchstr=$2

if [ -d filesdir ]
then
	echo "First argument does not represent a directory"
	exit 1
fi

nbfile=`grep -r "$searchstr" $filesdir -c | wc -l`
nbmatching=`grep -r "$searchstr" $filesdir -n | wc -l`

echo "The number of files are $nbfile and the number of matching lines are $nbmatching"
