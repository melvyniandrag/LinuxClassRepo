#!/bin/bash

read -p "Enter a number: " count
if [ $count = 100 ]
then
	echo "Number is 100"
elif [ $count > 100 ]
then
	echo "Number is less than 100"
else 
	echo "Number is greater than 100"

fi
