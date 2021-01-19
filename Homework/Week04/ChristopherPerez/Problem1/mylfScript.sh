#!/bin/bash


echo The first if will check if your number is greater than 20.
read -p "Choose a number, any number: " num

if [ $num -gt 20 ]
then
	echo nice number
else
	echo not nice number
fi

read -sp "Whisper this number in me in private, no one will be able to see it! " num2
echo ""
if [[ "$num" < "$num2" ]]
then
	echo "Your original number, $num, is less than your second number."
else
	echo "Your original number, $num, is greater than or equal to your second number."

fi

