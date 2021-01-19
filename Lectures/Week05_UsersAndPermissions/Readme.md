# EXTRA STUFF

For class notes, see Lecture.pdf. In this document are more things I was
thinking of doing but I don't think there will be time in class to cover, so I'm
leaving it here just in case.

## User limits

No time to cover this now. You can configure your system to limit the resources (e.g. cpu load, ram usage) available to a particular user.

### Hint at something more
If there is time.

Stickybit, setuid, setgid.
These are cool things about file ownership and permissions that we'll talk about later. Really cool, but not needed yet.


## Going further

For more information about these topics, feel free to read chapter 6 of the Evi Nemeth Unix/Linux Sysadmin book.

## More if

There are at least three ways to write ifs to check for conditions in bash.

You can write 

```
if [ 1 -eq 1 ]
then 
    echo "true"
else
    echo "false"
fi
```

You can also write

```
if test 1 -eq 1
then 
    echo "true"
else
    echo "false"
fi
```

The previous two are standard sh commands. The [[ ]] construct is a bash extension. It permits you to do more than the [] and test constructs allow, but it's not portable. 

One thing it can do is match regular expressions to strings.

```
$ var=aaab
$ if [[ $var == *ab ]]; then echo "match"; fi
match
```

but without the extra bracket:

```
$ var=aaab
$ if [ $var == *ab ]; then echo "match"; fi
$
$ #no match
```

More interesting uses of if:
* https://unix.stackexchange.com/questions/306111/what-is-the-difference-between-the-bash-operators-vs-vs-vs
* https://www.tldp.org/LDP/abs/html/testconstructs.html
* https://wiki.bash-hackers.org/commands/classictest

### Exercises

1. Look at the additional 'if/test' flags here: https://www.tldp.org/LDP/abs/html/fto.html
   Write some code using these operators.

### while loops

There are also while loops in bash. Many programming languages support while loops, the same thing I said about for loops. A while loop is a loop that will run forever until a specified condition is met. 

while ( alive ) {
    eat
    sleep
    etc.
}


```
i=0
while [ $i -lt 3 ]
do
echo $i
i=$[$i+1]
done
# 0 1 2
```

Another usage of test/while:
https://unix.stackexchange.com/questions/128204/what-does-while-test-gt-0-do

I increment the variable i in this loop, but this isn't of too much interest to us at this moment. In the notes I have a link that explains the multitude of ways to increment a variable in bash. It's not worth it to us right now to spend a half hour discussing the ins and outs, pros and cons, etc. The important message here is that bash, like many other languages supports a loop called a while loop.

https://askubuntu.com/questions/385528/how-to-increment-a-variable-in-bash

http://tldp.org/LDP/Bash-Beginners-Guide/html/sect_09_02.html



