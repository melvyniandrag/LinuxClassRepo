#!/bin/bash

letters=(a b c d e f g h i j k l m n o p q r s t u v w x y z ã ô â ç ê é ó ú í á à õ ü)
for letter in ${letters[@]}; do
	echo "$(grep -o $letter  $1 | wc -l), $letter"
done