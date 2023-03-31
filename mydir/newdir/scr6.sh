#! /bin/bash
echo "Enter the character"
read ch
echo "count=`ls $ch* | wc -l`"
