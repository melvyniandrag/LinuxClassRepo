echo "*************************"
echo "Find lines with an a"
grep "a" a.txt
echo "*************************"

echo "*************************"
echo "Find lines with an optional a"
grep "a\?" a.txt # find lines with an optional a.
echo "*************************"


echo "*************************"
echo "Find lines containing a?"
grep "a?" a.txt # find lines containing a?
echo "*************************"

echo "*************************"
echo "Find lines with one or more a s"
grep "a+" a.txt # find lines with 1 or more "a"s
echo "*************************"

echo "*************************"
echo "Find lines that end with a"
grep "a$" a.txt # find lines that end with a
echo "*************************"

echo "*************************"
echo "Find lines with a + character"
grep "+" a.txt # find lines with a +
echo "*************************"

echo "*************************"
echo "Find lines that end with a number"
grep "[0-9]$" a.txt # find lines that end with a number
echo "*************************"

echo "*************************"
echo "Find lines that contain exactly one letter"
grep "^[a-zA-Z]$" a.txt # find lines with one letter.
echo "*************************"
