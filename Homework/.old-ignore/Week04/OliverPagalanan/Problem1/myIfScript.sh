if [ $num1 -lt $num2 ]
then
        echo "$num2 is greater than $num1"
else
        echo "$num1 is greater than $num2"
fi

num3=11x
num4=21y

if [[ "$num3" < "$num4" ]]
then
        echo "$num4 is greater than $num3"
else
        echo "$num3 is greater than $num4"
fi

