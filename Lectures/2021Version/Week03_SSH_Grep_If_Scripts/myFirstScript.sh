#!/bin/bash

x1=1a
x2=2a
if [[ $x1 < $x2 ]]
then
	echo "$x1 < $x2"
else
	echo "$x2 <= $x1"
fi
