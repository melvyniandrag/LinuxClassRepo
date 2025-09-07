#!/bin/bash

random1=13
random2=9

if [ $random1 -ne $random2 ]
then
	echo "$random1 and $random2 are not equal"
else
	echo "Oh, apparently $random1 and $random2 are equal"
fi

string1=blahblah
string2=shoobidoobop

if [[ "$string1" == "$string2" ]]
then
	echo "Cool, $string1 and $string2 are the same string"
else
	echo "Oh well oh well $string1 and $string2 are not the same string"
fi
