#! /bin/bash
file=$1
test -f $file
if [ $? = 0 ]
then 
	echo "Regular file"
else
	test -d $file
	if [ $? = 0 ]
	then
		echo "Directory"
	else
		echo "Not exists"
	fi
fi
