#! /bin/bash
file=$1
sed 'y/aeiou/AEIOU/' $file > file2
