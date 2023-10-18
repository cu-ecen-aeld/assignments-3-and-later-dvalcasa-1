#!/bin/sh
# Author: dvalcasa

if [ $# -lt 2 ]
then
	echo "need two arguments"
	exit 1
fi

writefile=$1
writestr=$2

mkdir -p "`dirname $writefile`"
touch $writefile
if [ -f $writefile ]
then 
	echo "$writestr" > $writefile
else
	exit 1
fi

