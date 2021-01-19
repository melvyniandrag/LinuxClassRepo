#!/bin/bash

x1=5
x2=8
if [ $x1 -lt $x2 ]
then
    echo "$x1 < $x2"
else
    echo "$x2 <= $x1"
fi

x1=50g
x2=80g
if [[ $x1 < $x2 ]]
then
    echo "$x1 < $x2"
else
    echo "$x2 <= $x1"
fi
