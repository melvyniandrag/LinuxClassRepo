#!/bin/bash

echo "Enter a number between 0-20: "
read num

if [[ $num -lt 10 ]]
then
	num2=$((num+4))
	echo "$num plus 4 is $num2"
else
	num2=$((num-4))
	echo "$num minus 4 is $num2"
fi


if [ 2738 > -2738 ]
then
	echo "55 is bigger than 45"
fi
