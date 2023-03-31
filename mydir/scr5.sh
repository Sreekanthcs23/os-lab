#! /bin/bash
i="y"
echo "1.Add"
echo "2.sub"
echo "3.Mul"
echo "4.div"
while [ $i="y" ]
do
	echo "Enter first no"
	read n1
	echo "Enter second no"
	read n2
	echo "Enter option"
	read op
	case $op in
		1) echo "Result = `expr $n1 + $n2`";;
		2) echo "Result = `expr $n1 - $n2`";;
		3) echo "Result = `expr $n1 \* $n2`";;
		4) echo "Result = `expr $n1 / $n2`";;
		*) echo "Inavalid option";;
	esac
	echo "Do you want to continue"
	read i
	if [ $i != "y" ]
	then 
		exit
	fi
done
	
