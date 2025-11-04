# Week 02 Class outline
At this point, you know a handful of bash commands. In this lecture, we will learn a little bit more about bash, about Linux, and we'll introduce a very useful program called git.

## jobs vs processes
----------------------
whats a job, whats a process
NOTE actually we'll skip this for now. It's tough to motivate jobs and processes without jumping into a discussion of signals. And to talk about signals then you have to talk about kill. Then it would be nice to talk about programs that send signals too. So we'll talk about programs.

## io redirection
-------------------------------
show how processes have stdout, stderr, stdin.
use >, >> 1> 2> to send output to different locations.

### > and 1>

echo "hi" > hi.txt
echo "1,2,3" > numbers.csv
pwd > myPWD.txt

wc myPWD.txt 1> wordcount.output
echo "bye" 1> bye.txt

### 2>

### >>, 1>> and 2>>


## pipes
-----------------------------------------
Building on your knowledge of `stdout`, pipes are a fundamental part of shell scripting.
The stdout of one command flows through a pipe to the stdin of another.
Consider the following examples:

1. Can't remember the ip address of the machine you sshed into 10 minutes ago?
```
history | grep
```

2. Say you have a CSV file and you want the value in the 2nd column on line 142.
Here's 3 ways to do ranging from worst to best.

```
head -n N myFile.txt | tail -n 1 | cut -d"," -f2"
tail -n +N myFile.txt | head -n1 | cut -d"," -f2"
awk -F',' "NR==$N {print $2; exit}" myFile.txt
```

3. Want to know how many unique lines are in a file?
```
sort | uniq
```

4. Of you have a CSV of numbers and you want the largest value in column 2 how would you do it?
Here's 2 ways.
```
cut -d "," -f2 data.csv | sort -gr | head -n1
awk -F, 'NR==1 || $2>max {max=$2} END{print max}' data.csv
```

5. Create a file with a few lines that say dog and a few that do not.

grep -w dog | wc -l

grep -i dog | wc -l

8. Filter out empty lines grep -v '^$' file.txt | wc -l

9. Find largest file ls -l | sort -k5 -n -r | head -10

11. Alternative using du (easier for beginners)
du -ah . | sort -h -r | head -10


du -ah . → shows size + path for every file/dir recursively

sort -h -r → sort human-readable sizes, largest first

head -10 → top 10 largest

### awk
As you saw in 2 of the examples above, there is an amazing tool on Linux called awk. This is one of my favorite Linux tools of all time, and we'll devote a full lecture to this amazing tool later in the semester. Awk is actually a programming language, but it was designed to be the best tool ever for processing structured data files.

## programming on Linux
You can write programs on Linux. In this class we'll talk about python and C++ because these are two of my favorite languages, but you can program in any language you want on Linux.

### python
1. install
2. write and run hello world
3. write a program that writes to std out
3. take that program and pipe it's output to grep
3. make the program write to stderr. note that grep does not filter out the junk, because pipes only work on stdout.
3. write and run a program that will run forever. kill it with ctrl C

# vim

yank and paste

"<register>y<motion>
"<register>p
"<register>p

"<register>p
of 
"<register>P

and 


this week we will only focus on one motion. yy. 

there is also a "delete" (cut)
dd delete a line

"add
delete and place in register a.

This week we will continue our journey learning vim. Have you ever wanted to copy more than one  thing? Maybe you're working on some code and you want to copy two functions to paste into another file. Vim lets you do that!

Practice 
a
b
c
