#! /bin/bash
str1=$1
str2=$2
test $str1 == $str2
if [ $? == 0 ]
then
	echo "strings are equal"
else
	echo "strings are not equal"
fi
