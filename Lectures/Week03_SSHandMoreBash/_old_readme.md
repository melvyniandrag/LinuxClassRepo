# Week 03 Lecture

This week we will learn a few more command line tools.

The main focus of todays class is to introduce the following concepts:
* pattern matching in bash
* grep 
* regular expressions
* bash arrays
* bash loops

Don't forget - in a few weeks we are going to be doing some cool stuff, setting up various linux servers, running a website on Linux, manipulating text in cool ways, and we'll learn two more languages. For now we are still familiarizing ourselves with common command line tools so those later activities will be easier to understand.

Schedule:

## [ 7:00 - 7:10 ] Homework Review
## [ 7:10 - 7:20 ] Pattern matching in bash 
## [ 7:20 - 7:40 ] Grep
## [ 7:40 - 8:00 ] Exercises
## [ 8:00 - 8:20 ] Grep and Regexes!
## [ 8:20 - 8:30 ] Exercise
## [ 8:30 - 8:35 ] vim pro-tip
## [ 8:35 - 9:00 ] Arrays
## [ 9:00 - 9:15 ] for loops
## [ 9:15 - 9:28 ] Exercise
## [ 9:28 - 9:43 ] Homework Discussion
## [ 9:43 - 9:45 ] Hacktoberfest / Open House

( If overtime we can look more at if / test )


## [ 7:00 - 7:10 ] Homework Review
See the week 2 homework directory.
 
## [ 7:10 - 7:20 ] Pattern matching in bash 
No we get into pattern matching in linux. A common way to match patterns in Linux is to 
use * when using bash. There are a couple of more commands. Here they are:
* \* - match zero or more characters
* ? - match any single character
* [xyz] - match any characters in the set.

And here's a reference: https://www.linuxjournal.com/content/pattern-matching-bash

Lets make a directory called dir, and put a bunch of files in it. 
Lets name them:

```
$ mkdir dir
$ cd dir
$ touch cow coffee core care cape apple 
$ ls
$ ls c?re
$ ls c*
$ ls ca?e
$ ls ca[rb]e
$ ls ca[rp]e
```

You can use these wild cards in the terminal. So, for example, if you want to get the number of lines in all of the files in your current directory you could

```
cat * | wc -l
```

`cat` concatenates all the files ( * ) and dumps them to stdout. Via a pipe, the stdin of `wc -l` reads that stdout and processes it.

## [ 7:20 - 7:40 ] Grep

Now lets look at some more advanced pattern matching used in Linux via the grep command. 
Grep stands for Global regular expression print, it uses regular expressions to search for strings. "What's a regular expressions???" - we'll get to those nasty things in a second, but first we'll take a peek at grep.

Now, grep is immensely useful, as we already saw last week. Last week we typed

```
history | grep wget
```

to look through our messy bash history to find exactly the command of interest to us, to see what files we downloaded in the past and to potentially download them again.

A poem I like:
https://www.cc.gatech.edu/~spencer/poems/woods.txt

You can wget the poem

We are going to cover a bunch of grep options to pick apart this poem.

1. -i -> grep -i HARNESS woods.txt
2. -w -> grep -w arness; grep -wi Harness 
3. -v -> grep -v arness # inverse grep
4. -r -> mkdir -p a/b; mv woods.txt a/b; grep -r arness *
5. -n -> grep -rn arness *
6. grep can match lines after + including pattern `grep -A1 arness woods.txt `
7. grep can match lines before and including pattern  `grep -B1 arness woods.txt`
8. grep can match lines around pattern `grep -C3 arness woods.txt`
7. -l -> grep -l arness * # list files containing pattern
    > remember if we see any irrelevant error messages from grep, we can redirect them to the ether.
    ```
     grep -l arness * 2> /dev/null
    ```

    e.g.
    ```
    $mkdir dir
    $grep -l arness *
    grep: dir: Is a directory
    woods.txt
    ```
    
    BUT
    
    ```
    $grep -l arness * 2>/dev/null
    lecture.txt
    woods.txt
    ```

A reference for later:
https://opensourceforu.com/2012/06/beginners-guide-gnu-grep-basics/

## [ 7:40 - 7:50 ] Exercises

Use the above patterns on the file `hamletSolilquy.txt`. See what patterns you can extract. Make sure you test all of the patterns above, as you need to understand grep very well for your homework!

## [ 7:50 - 8:20 ] Grep and Regexes!

Ah, but we have yet to get to regular expressions!

They say when a programmer has a problem and says "I know, I'll use a regular expression!". This is because regular expressions are tricky and easy to screw up if you don't pay attention. The lesson here is the same as with using vim - don't complain that the thing is hard, just learn to use it and then use it without whining! I suspect this proverb is so popular because alot of people don't pay attention to what a regex ( that's short, slang for a regular expression ) is and how to use it. 

Regular expressions are for pattern matching. They are found in every major programming language out there - C++, Python, Java, etc. and you can use them in the bash shell too along with the 'grep' utility.

https://www.gnu.org/software/grep/manual/html_node/Basic-vs-Extended.html

There are two types - regular and extended. We'll just look at the basic ones - extended is about the same. In your free time click the link above and read it quickly. You'll see they are about the same.

> In basic regular expressions the meta-characters ‘?’, ‘+’, ‘{’, ‘|’, ‘(’, and ‘)’ lose their special meaning; instead use the backslashed versions ‘\?’, ‘\+’, ‘\{’, ‘\|’, ‘\(’, and ‘\)’.

The period (.) matches any single character.
? means that the preceding item is optional, and if found, will be matched at the most, once.
* means that the preceding item will be matched zero or more times.
+ means the preceding item will be matched one or more times.
{n} means the preceding item is matched exactly n times, while {n,} means the item is matched n or more times. {n,m} means that the preceding item is matched at least n times, but not more than m times. {,m} means that the preceding item is matched, at the most, m times.

Some more syntax:
1. ^ (Caret)   =   match expression at the start of a line, as in ^A.
2. $ (Question)    =   match expression at the end of a line, as in A$.
3. \ (Back Slash)  =   turn off the special meaning of the next character, as in \^.
4. [ ] (Brackets)  =   match any one of the enclosed characters, as in [aeiou]. Use Hyphen "-" for a range, as in [0-9].
5. [^ ]    =   match any one character except those enclosed in [ ], as in [^0-9].
6. . (Period)  =   match a single character of any value, except end of line.
7. * (Asterisk)    =   match zero or more of the preceding character or expression.
8. \{x,y\} =   match x to y occurrences of the preceding.
9. \{x\}   =   match exactly x occurrences of the preceding.
10. \{x,\}  =   match x or more occurrences of the preceding.

That's it! So, given the file a.txt ( see this directory )

We can do the following
```
$ grep "a" a.txt # Find lines with an a
$ grep "a\?" a.txt # find lines with an optional a.
$ grep "a?" a.txt # find lines containing a?
$ grep "a\+" a.txt # find lines with 1 or more "a"s
$ grep "a+" a.txt # find lines  containing "a+" 
$ grep "a$" a.txt # find lines that end with a
$ grep "[0-9]$" a.txt # find lines that end with a number
$ grep "^[a-zA-Z]$" a.txt # find lines with one letter.
$ grep "a\{2,\}" a.txt # find lines with 2 or more "a"s
```


## [ 8:20 - 8:30 ] Exercise
Change a.txt and change some of the grep patterns and verify that they work as expected on your system. You might have a weird version of grep installed, so let's make sure grep works the same for all of us.



## [ 8:30 - 8:35 ] vim pro-tip
another vim tip is that you can go to the bottom of a file with 
shift+g. top is gg.

The rm command is a particularly dangerous command on your system, as we have discussed before. Whereas windows has a "trash can" when you delete a file, Linux does not. When you rm a file, it is gone forever - there are some hail mary ways to possibly, maybe, pleasepleaseplease save your rm-ed files, but generally speaking, if you rm a file it is gone for forever. Your homework deals with using your bashrc and an alias to make rm safer.



## [ 8:35 - 9:00 ] Arrays
This article starts out by saying:
"the intent of this article is to avoid having to RTFM", it's a great read!
https://medium.com/@robaboukhalil/the-weird-wondrous-world-of-bash-arrays-a86e5adf2c69

What's an array? It's a container of values. There's a bunch of uses for this! It's a list of values!
There are many data structures you can use for the values you are manipulating in your program, an array is just one container for holding them. 
You know there are priority queues, hash maps, a whole bunch of binary trees, etc., etc., to learn about these you need to take an algorithms class, or read an algorithms book.

An array is something like 

students=["omar", "Elizabeth", "Mackenzie" . . . ]

All languages that I know use arrays. Maybe there is a language out there that doesn't support arrays, but I don't know of it yet.

The array syntax in bash is 

```
arr=(1 2 3 4)
```

you can put strings and numbers in there like

```
arr=(1 2 3 "hello")
```

In bash to see variable contents you use the `$`. For example, if you say

```
a=1
echo $a
```

You can also wrap the variable with curly braces like this

```
b=1
echo ${b}
```

A time when you would use this curly brace syntax is to add extra characters to the output of a variable. For example:

```
z="cat"
echo $z
echo $zs
#error
echo ${z}s
```

Without the curly brace in this situation, bash thinks the variable is called "zs"

Bash variables do require the curly braces, however. I'll repeat now that I don't love the bash syntax, but bash is super useful, and it's everywhere, so we all have to know about it. Kind of like javascript.

```
arr=(1 2 3)
echo ${arr[0]}
# prints 1
echo ${arr[1]}
# 2
echo ${arr[2]}
# 3
```

If you omit the curly brace, like this:

```
echo $a[0]
# 1[0]
```

You see bash treats the "[0]" as a string. We won't go into the low level explanation of why this happens, but it does and that's just the way bash works. So you need the curly brace. Also, notice you won't get 'out-of-bounds' exceptions or crashes due to accessing elements that are outside the bounds of the array.

```
arr=(1 2)
echo ${arr[5]}
# nothing
```

it is what it is. Notice that bash uses zero indexed arrays. For all the yuckiness of bash array syntax, at least it uses zero indexing. And it's not that yucky either, is it? Just remember to use the curly braces!

How to dump the array and see the contents? This is another important thing you might want to do!

```
arr=(1 2 3)
echo ${arr[@]}
```

So the ampersand is used for dumping all the array contents.

Now let's get really funky for a second - bash array elements don't need to be sequentially indexed!!

Look at this example:

```
array[0]=10
array[4]=4
echo ${array[@]}
# 10 4

echo ${array[1]}
#nothing
```

Depending on your familiarity with other languages - but for this you can probably just use your intuition - this is really weird! Bash arrays are zero indexed. So you would expect the array to start with element 0, then there's element 1, then 2, etc.. But not with bash. You can have an array containing elements 0, then 4. Or you can make an array like this:

```
array2[10]=1
array2[12]=1
array2[100]=2
echo ${array2[@]}
```

We'll put arrays on the back burner for a second while we look into another topic.

## [ 9:00 - 9:15 ] for loops
For loops are a common construct in many programming languages! C, Java, Python, Ruby, Javascript etc. all use this construct, so you've probably seen it before. Bash has it too.

A common use case of the for loop is when you want to loop over something a predetermined number of times. You'll say "for iteration = 1 to 100 do a thing. In bash to write this you say:

```
for i in $(seq 1 10)
do
    echo $i
done
```

type that a few times to make sure you understand it. ( seq is another command line tool to generate a sequence of numbers )

You also might want to loop over an array:


```
array=(1 2 3)
for i in ${array[@]}
do
	echo $i
done
```

You might want to loop over an array by index, too! Now if you don't know why you would want to do this yet, don't worry about it, I'm going to show you the syntax anyway, and maybe you'll thank me sometie 10 years from now. Think about what I said about myself and python dictionaries.

Look at our previous array

```
array=(1 2 3)
for i in ${!array[@]}
do
	echo $i
done
```

The exclamation point tells the loop to print out the array index instead of the array value. Notice that this prints out 0 1 2 - these are the indices of the array, because bash is zero indexed.

But, remember that bash arrays are strange and don't require sequential indexing.

```
arr[10]=1
arr[15]=2
for i in ${!arr[@]}
do
	echo $i
done
# 10 15
```

## [ 9:15 - 9:28 ] Exercise
Write a bash program to create a bash array with indices:

`1, 3, 5, 7, 9, 11`

and values

`one, three, five, seven, nine, eleven`

Your program should user a for loop to print out:

```
$ bash myScript.sh
arr[1]=one
arr[3]=three
...
arr[11]=eleven
```

As guidance, look at these example carefully and think about how you'll modify them:

### Example A
```
arr[10]=1
arr[15]=2
for i in ${!arr[@]}
do
	echo $i
done
# 10
# 15
```

### Example 2

```
arr=(1 2 3)
echo ${arr[0]}
# prints 1
echo ${arr[1]}
# 2
echo ${arr[2]}
# 3
```

## [ 9:28 - 9:43 ] Homework Discussion
Read the Homework example.

* Show frequency chart
* Talk about hacking, the letter swapping encryption scheme
* `cd ~; bash countingFrequencies.sh | sort -nr` show the output. DONT SHOW THE CODE!

## [ 9:43 - 9:45 ] Hacktoberfest / Open House
