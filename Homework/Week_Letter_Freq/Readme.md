# Week 03 Homework

What a good assignment! A combination of Linux, hacking, statistics, encryption, and Literature.

## Motivation

A common ( baby ) encryption scheme is to change letters in your text. Let me set you up for this:

For example change the text like this:
A -> B
B -> C
C -> D
...
Z -> A

Then you send your friend a message:

MJOVY

What does this mean?? ( LINUX )

A hacker may not know the changes you made. How would a hacker know what letters you swapped? You may have adopted instead:

A -> C
B -> D
...
Z -> B

So you might use a compilcated shift of letters like this:

A -> 1
B -> 6
C -> ?
...
Z -> =
? -> ^

or the like, and then you'll send a message like:

a.lsire3$#$;alkn''$%%%

and think you've outsmarted everyone! Wrong.

Hackers can use basic statistics against you and crack this silly encryption scheme you devised.

## A smarter attack

It is well know that  letters in English follow a statistical distribution.

Have a look at this table:
http://pi.math.cornell.edu/~mec/2003-2004/cryptography/subs/frequencies.html

This means that if you get a huge body of English text and count the frequencies of the various English letters, 'e' will come up 12% of the time, 't' will appear 9% of the time, 'a' 8% of the time, and so on.

So all a hacker needs to do is see which symbol in your letter appears 12% of the time, and translate that letter to e. Similarly, the hacker finds the second most common symbol in your message and interprets that symbol as a t. And so on. So if the most common symbol in your message is '^', the hacker will replace all the '^' occurences with 'e'. Easy. pwned.

## Your assignment
Verify the distribution of letters in the three English Language works present in this directory.

Use the linux commands you know to count the frequencies of letters a, b, c, d 

You are going ts need to use the command `grep -o $CHAR`. This counts the frequency of the letter $CHAR. For example, 

`cat file.txt | grep -o a | wc -l`

will count the number of times that 'a' appears in file.txt

`cat file.txt | grep -io a | wc -l`

Will count ignoring the case of the letter ( upper case / lower case )

## Expected output

I was going to demand a strict output, but I'll let you be creative. The output must clearly illustrate that you computed the counts of letters in your file, and it must be sorted. The quickest output I came up with was this:

```
melvyn@thinkpad-t450$ SEQUENCE_OF_SCRIPT_CALLS_AND_BASH_COMMANDS
e,xxx( count of e in The War Of The Worlds )
t,yyy
etc.
```

And you must clearly show me that you did whatever magic you come up with to all three files. If I have to stare at your submission for more than 5 seconds to understand what you've done, it's no good. Do whatever you want, but the output must be SORTED and CLEAR!!

## Submission guidelines

Code should that you used bash and Linux commands to count the letters and sort them into a list of descending frequencies.

Submit a combination of screenshots and scripts that indicate that YOU did the work on your machine, and that you got the proper answer.

Due September 25th at Midnight on Blackboard, not a second later!! You're going to need to flex your brain muscles on this a little bit, don't give up.

33% for each right answer. The books may or may not agree with the statistical distribution of letters as linked above. I'm going to compare what you get to what I got. I repeat - it may or may not agree with the expected distribution - but it should. Again, I am the standard of correctness for this assignment. If your distribution agrees with mine, you're golden.

