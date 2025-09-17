# Welcome to Intro to Linux
Schedule:
1.  7:00 - 7:20 Why Linux/Unix 
2.  7:20 - 7:30 About the class
3.  7:30 - 7:50 Connect to machine
4.  7:50 - 8:00 Bash Part 1
5.  8:00 - 8:05 Break 
6.  8:05 - 8:30 Bash Part 2
7.  8:30 - 9:00 Vim
8.  9:00 - 9:05 Break 
9.  9:05 - 9:35 Bash Part 3
10. 9:35 - 9:45 Homework 

## Why Linux / Unix? [ 7:00 - 7:30 ]
Let me give you a reason to learn Linux. Look what you can do:

```
melvyn@machine$ telnet towel.blinkenlights.nl
(exit with CTRL + ], then quit)
```

\*nix refers to a family of similar operating systems that have an interesting history. They are different from Windows, but are as or more popular than windows on personal computers and on servers.

Demos:
1. Website running linux
2. Robot running linux ( youtube )
3. Cars run Linux
4. Laptop runs linux ( show T series laptops )
5. Raspberry Pi + Beagleboard demos
6. Playstation4 runs a Unix operating system
7. telnet starwars

There is alot of money to be made.

You can do anything in \*nix, and whatever can't be done - you can code it yourself and share it with the community. You may not have a grasp of how powerful computers are if you are early in your career and all you've done is surf the web and play games.

## About this class [ 7:20 - 7:30 ]
Run through the syllabus. 

There is a class discord, have everyone connect so we can chat about the class. It's faster than email and it's a place where you all can chat with each other in case I'm too busy or asleep when you ask a question at 1AM.

This class will show you some really cool stuff. At the end of this class you will be a much better programmer/sysadmin than you are today. If you do the work, I can guarantee it. 

No late assignments.

## Get everyone connected to a machine [ 7:30 - 7:50 ]
Present options for class:
1. Beaglebone black ( you're going to need an sd card or usb stick later too )
2. Digital ocean rental ( $5/month for a machine, plus a few dollars here and there for additional rentals, maybe an additional 10 bucks total for the semester).
3. Get a laptop ( you're going to need an sd card or usb stick later too )

Take a few minutes to show buying options.

I recommend getting a laptop, using it everyday for everything to get used to linux. It's going to take you 5 years to become a linux wizard if you use it everyday. If you use it once a week, you'll take a little while longer. The same goes for anything related to computers.

For this first class we have no actual Linux machine to use. I don't want to waste time getting a machine - the burden is on you to have one by next week. For now we are going to use the git bash terminal installed on our windows machines. Linux is so good that Microsoft is slowly rolling Linux features in Windows, after just a handful of years earlier they called Linux "Cancer" and wanted to destroy it!

## Bash Part 1 [ 7:50 - 8:00 ]
1. ls
2. ls -l
3. ls -a
4. ls -la
5. cd
6. cp
7. mv
8. whoami
10. mkdir
11. mkdir -p
11. touch
12. rm
13. rm -r
9. which
10. cp -r

## Break [ 8:00 - 8:05 ]
Designated time for mental relaxation.

## Bash Part 2 [ 8:05-8:30 ]
14. cat
15. echo
16. man
17. wc
18. wc -c $fileName
19. wc -l
20. wc -w
21. md5sum
22. more
23. less
24. unzip
25. zip
26. tar
27. tar -xvzf
28. cut -b
29. cut -c ( just like cut -b on every machine I've seen. In the future -b ( byte) and -c ( character) will be different. Ill give some insight on that later in the class, and if you know Java + C you will likely have a bit of insight on the definitions of byte and character, where they are the same, and where they are different. There is no time for that now, and if you already have insight, just keep it to yourself for now haha.
30. tree
31. lsblk ( plug in a usb stick and see that it changes )
32. du - list disk usage globally
33. df - list disk usage by file
34. wget

## Vim [ 8:30 - 9:00 ]

### Why learn vim
As you've seen a major part of working on Linux is doing stuff on the command line. 
If you're on your laptop, you might use other graphical tools. You can create a directory, for example, by right clicking and going to 'create directory' or whatever as you do on windows, but you'll often work on the command line, or create directories in your code, and things like 'mkdir' are useful for that. 
If you are a web developer maintaining a website, youll often connect to a command line interface and do things there, because you won't have a monitor in front of you. 
If you remotely connect to a computer, you'll maybe need to edit a file. for this you'll need a command line editor. Here's your first dose of linux/unix/bsd culture! There is alot of playful fighting in the \*nix world about the best way to edit files on the command line. Mainly the war is around two editors, https://en.wikipedia.org/wiki/Editor_war, emacs and vim. I like vim. Some folks like emacs. I started on emacs a decade ago, but when I learned vim I found that I liked it more and I haven't looked back in about 10 years. I'm going to teach you vim, and if you want to learn Emacs you'll have to do it on your own time. 
If you get a job and have to edit a file on a server, and you fire up vim and edit it smoothly you'll instantaneously become the celebrity of the office. You'll be one of the cool cats. Emacs would also get you cool points.

But vim is featured in every standard linux distro, while emacs is not! 
Whatever, too much said already. We're using vim for this class.
There are simpler editors like pico and nano, but I know vim by heart so that's what I use and teach!

### Basic Vim Work flow
Vim is a 'mode based' editor. 
Hit i to enter insert mode. Start typing as normal.
Hit esc to get out of insert mode.
Type :wq to save and quit. 
Thats 99% of what you'll do in this class.

### More vim commands to make your work better.
1. h, j, k, l
2. I prefer to just use the arrow keys
3. modes i, esc
4. quit with :q. To save and quit you use :wq or :x. If you want to know the difference, google the diff between :wq and :x. there is a slight difference, but it doesnt matter.
5. dd to delete a line
6. w to go forward a word
7. e to go to the end of the next word
8. b to go to the previous word beginning.
9. u is undo
10. CTRL + r is to redo.
11. to go forward 5 words, 5w
12. To go back 5 words, 5b.
13. v puts you in visual mode so you can delete select multiple lines 
14. CTRL + v is a cool feature, you can keep the cursor fixed and select multiple lines. Use this to delete the first few chars of every line.
15. y is yank. copy.
16. p is paste after the cursor
17. shift p is paste before the cursor

## Break [ 9:00-9:05 ]

Designated short break for bathroom + relaxation.


##Bash Part 3 [ 9:05-9:35 ]

1. Return value of last command $?. Play with 'echo $?' vs '$?'.
Explain the output of

melvyn@machine$ echo "hello world"
hello world 
melvyn@machine$ $?
0: command not found
melvyn@machine$ $?
127
melvyn@machine$? echo $?
0


2. The coupe de gras. Registers in vim. Vim remembers the things you've yanked in the past. Type :reg
See that vim remembers the stuff you've put on your clipboard in the past.
Exercise
Type:
Hello
World
Foo
Bar
Baz
dd Hello
dd World
highlight and yank the other three
Then look at clip board.
Paste world
Paste Baz
Foo
Bar
Baz
Look at :reg and see what it remembers. I think it remembers the dd stuff but only remembers the latest yanked stuff.
Paste the things from your registers with <reg id>p e.g. ( when  in normal mode, not insert mode ) "1p, see what happens. 


## Homework Discussion [ 9:35 - 9:45 ]
Look at and discuss homework.
