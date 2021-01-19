#!/bin/bash
if [[ 1 < 2 ]]
then 
	echo "1 is less than 2"

fi
newNumber=20
oldNumber=21
if [[ $newNumber = $oldNumber ]]
then
	echo "Numbers are the same"
else
	echo "Numbers are not the same"
fi
