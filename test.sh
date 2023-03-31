a=$1
b=$2
c=$3
if test $c = +
 then echo Sum of number=`expr $a + $b`
elif test $c = -
 then echo subtract of number=`expr $a - $b`
elif test $c = *
 then echo Multiply of number= `expr $a \* $b`
elif test $c = /
 then echo subtract of number=`expr $a / $b`
else echo Invalid
fi
