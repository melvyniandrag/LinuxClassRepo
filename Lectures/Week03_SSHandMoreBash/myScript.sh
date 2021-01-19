array[1]=one
array[3]=three
array[5]=five
array[7]=seven
array[9]=nine
array[11]=eleven

for i in ${!array[@]}
do
	echo "arr[$i]=${array[$i]}"
done
