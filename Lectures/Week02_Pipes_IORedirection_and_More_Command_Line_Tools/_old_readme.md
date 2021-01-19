# Week 2 Lecture

## A bit of padding in case the lecture gets slow
1. Sichuan recipe and the importance of doing cool stuff. Computers and linux are for doing cool stuff. Linux is another tool. you can also cook.
2. Mention grant for HSI and look at the requirements for grant writing. Glad to have some sophomores and juniors ( how many soph/fresh/jun in tihs class? ) so if we win the grant, they will profit. For the seniors ,really soak up everything I have to say in this class as it is one of your last classes here
3. Hacktoberfest hackathon and Mathtestmaker
4. Open house - what do people want to do for open house?? Robots? Websites? Apps? Let's do something!


## Plan of attack
* 7:00 - 7:30 pipes
* 7:30 - 8:00 if/test/comparisons
* 8:00 - 8:05 break
* 8:05 - 8:30 stdin, stdout, stderr
* 8:30 - 8:45 A programming interlude
* 8:45 - 9:00 processes
* 9:00 - 9:05 break
* 9:05 - 9:35 More about processes
* 9:35 - 9:45 homework discussion.

## [ 7:00 - 7:30 ] pipes
One of the best parts of Linux Shell Scripting is pipes. Pipes allow you, along with a few other commands that we'll cover shortly, to chain simple command line tools together. This is the essence on \*nix, scripting, really - chain together a bunch of simple but thoroughly tested ( and correct ) programs to do something larger and more interesting. 

Good commands to use with pipes:
* sort
* uniq
* cut
* cut -b
* cut -c
* cat
* echo
* tee
* md5sum
* sha256
* history 
* grep  

For a better example, let's find the largest number in a file of numbers.

`See Code/NumbersPipeExample` where we find the largest number in txt file with a chain of piped commands.

Some cool pipe examples:

* cat file | sort
* cat file | sort -n
* cat file | sort -g
* cat file | sort | uniq
* cat file | uniq # note that this does not work.
* echo hello | cut -b1-2
* echo hello | cut -c1-4
* echo "hello world" | cut -d" " -f1
Note how cut with d and f is finicky
* echo "hello      world" | cut -d" " -f2 # many spaces between hello and world.
By default cut uses TAB ( \t ) as delimiter.
* cat file  | md5sum
* md5sum file
* cat file | sha256
* history | grep "that cool command I can only remember part of" # I do this at least 50 times a day

Have a look at where all of the different tools are installed on the computer to emphasize that all these 'bash commands' aren't really 'bash commands' at all. These are simple programs that come installed in Linux and they can be used to  


If time, really dwell on this as it is important. Ask questions, bs about it, really dwell as this is important. If all else fails ask students to write a hundred piped commands.

Have students search the internet for cool pipe examples.

### 7:25 Exercises
Have class experiment with pipes to make sure they understand.

## [ 7:30 - 8:00 ] if/test/comparisons
The bash syntax for if is 

```
if [ condition ]
then
 command
fi
```

One more useful piece of information is that bash generally interprets values as strings, unless they can be used as numbers, in which case it assumes they are numbers. https://www.tldp.org/LDP/abs/html/untyped.html.

Comparison operators for numbers in bash are:

1. -eq
2. -ne
3. -gt
4. -ge 
etc.

Comparison operators for strings are:

1. =
2. !=
etc.

for more information see here https://www.tldp.org/LDP/abs/html/comparison-ops.html

```
# an arithmetic comparison
x1=1
x2=2
if [ $x1 -lt $x2 ]        
then
    echo "$x1 < $x2"
else
    echo "$x2 <= $x1"
fi
```

Then this script will fail, because you are using an arithmetic comp on strings:

```
x1=1a
x2=2a
if [ $x1 -lt $x2 ]        
then
    echo "$x1 < $x2"
else
    echo "$x2 <= $x1"
fi
```

You can easily fix this with:

```
#
# The old bash advice is to double quote all variables in bash to make sure they are interpreted as a single value.
# 
# notice the difference between how this script runs with bash and with sh
#
# sh is the bourne shell, bash is the bourne again shell
#

x1=1a
x2=2a

if [[ "$x1" < "$x2" ]]
then
    echo "$x1 < $x2"
else
    echo "$x2 <= $x1"
fi

if [ "$x1" \< "$x2" ]        
then
    echo "$x1 < $x2"
else
    echo "$x2 <= $x1"
fi
```

So I've shown you how to use if and some comparisons and highlighted some pitfalls, okay?

Notice how I made variables and how I used them in here. Now I want to show you a bit more about variables in bash. Again, what I'm showing you will work with sh (probably) but I take no responsibility for it if it doesn't. There are a million shells out there - a cool one I came across recently is fish. I think you install it with apt-get install fish, or fsh, can't remember, but I guess it purports to be a beginner friendly shell. I've never had any issue with bash, I've used the c shell maybe once or twice on an old server, and zsh a few times, but I like bash.


### 7:50 Exercises 
Have class write some if/else/test comparisons to make sure they understand.


## [ 8:00 - 8:05 ] break
Much needed break.

## [ 8:05 - 8:30 ] stdin, stdout, stderr
All linux processes have at least 3 "file descriptors" or communication channels with the outside world. Does anyone not know what they are? Then Ill tell you. You have standard in, standard out, and standard error. We've already begun using them in this class briefly with the > operator. 

Open vim and create a file. Type a couple of words in it, we're going to use that file for the next exercise.

`wc fileThatExists > log` You see nothing. Running cat log will show you the output of the wc tool

`wc filethatdoestexist > log` You see an error in the shell, cat log shows nothing. There was no std out of wc, but there was err output

`wc filethatdoesntexist 1>log 2>errLog` Now there is no error on the screen, but cat errLog shows the error from wc.

`wc filethatdoesntexist >log 2>errLog` You can put the 1 or not, it assumes the 1 is for stdout, 2 is for stderr.

A common "idiom" you'll see is

`wc file 1>place 2>&1` that redirects both stdout and stderr to the same location.

You can also write 
`wc filethatdoesntexist &>place` to redirect both to 'place'.

As an aside look what vim does to the files. Not essential stuff, but this is just to deepen your knowledge of vim and how much attention to detail is required in programming. What if you are working on a project and there is a datafile that shouldn't have newlines. Then you peek in the file with vim and absent mindedly close it with :wq. You could cause an error that could take days to debug!!

```
wc errLog
0 blah blah
```
There are no newlines

Not open errLog with vim and quit immediately with :q

```
wc errLog
0 blah blah
```
Now open with vim and close with wq
wc errLog

Now there is a newline! Writing with vim - vim always puts a newline at the end of the file.

Now lets move on to standard in. We've already seen alot of it. Pipes use standard in!! You can always pipe the stdout of one process to the stdin of another!

```
cat file | wc
```

The stdin of wc picks up the stdout of file! Processes can take inputs and give outputs.

There are various ways to feed a process's standardin. Some tools allow you to just give it as a positional argument, like wc.

```
wc file
```

'file' goes to the stdin of wc.

You can also be more explicit. We saw that stdout is "1" for some mysterious reason, and stderr is "2" for an equally mysterious reason. Well, not a mystery, this is just boring technical stuff. Some programmer way back when made the decision to associate these numbers with the indicated channels, and that's the way it is! Why do we type "cp" to copy a file??? Just another boring technical reason, that's how the computer program was written , right?? Well, stdin is 0. Also, output is associated with > and >>, input is associated with <

So we can also type `wc < file` or `wc 0< file`

I don't know if I've ever written this syntax, maybe once or twice. I'm an application and operating system developer mainly. It certainly isn't in my day to day work, but it's good to know in case you come across it in a script, an exam, or have to teach it!


Of course, you can mix these things

`$wc 0< file > log`

Also, don't forget about "append" vs write when it comes to the stderr/stdout stuff

```
$ wc filethatdoesntexist 2>> err
$ wc filethatdoesntexist 2>> err
$ wc filethatdoesntexist 2>> err
$ wc filethatdoesntexist 2>> err
$ cat err
```

You'll see alot of error messages logged in "err"

An aside, maybe you're interested? How to pipe standard error?
https://stackoverflow.com/questions/1507816/with-bash-how-can-i-pipe-standard-error-into-another-process

A common thing you'll see and maybe want to do is make your processes shoosh! If a process is running and giving alot of output you don't want you can throw away the output channels.

```
$ wc f 2>/dev/null 
```

A common place to send unwanted output is to /dev/null, it just writes your output to the ether and you don't see it and it isn't logged anywhere.

The above command should give an error, but you won't see it, its just gone. There are many times you'll want to do this. I won't dream up some big situation right now to illustrate this to you, just know you'll see this all over the place in bash scripts and there will come a time, if there hasn't already, where you'll just want to throw away either stdout or stderr and never hear about it.

## [ 8:30 - 8:45 ] An Interlude For the Programmers
I'm a software developer, not an Operating System developer, as I suspect many of you will be. For those of you who want to system administrators you can largely ignore what I'm about to say, but it is interesting. 

When you write software on Linux, a fundamental thing you will do is write things to standard error and standard out. Most of the tools we're using in this class are C programs that do just that - they read stdin, and write to stdout and stderr. That's why you can use the `wc`, `md5sum`, `uniq`, etc. programs with pipes - because they are all written to use these channels.

In c++, for example, you may see

```
#include <iostream> // this gives you cout and cerr

int main(){
	std::cout << "Hello world!" << std::endl;
	std::cerr << "Oh no, an error!" << std::endl;
}
```

python also gives you sys.stdin, sys.stdout and sys.stderr.

```
# put the following in a file and run it
# call this output.py
import sys

sys.stdout.write("I go to standard out")
sys.stderr.write("I go to standard error")
```

```
python output.py 1>log 2>errlog
cat log
cat errLog
```

Notice the missing newlines here. Just a curiosity. 


Wait - you don't see the lack of newlines?!?! Try this then.

```
$python output.py 1>log 2>errLog; cat errLog | wc
0 5 20
```

We saw before there were newlines appended to the outputs of md5sum and echo.

\<Do you write software in a different language? Have you ever done this? cout? cerr? stdout.write? in your language? What is your language of choice? \>

## [ 8:45 - 8:55 ] processes
In this section we're going to talk about processes in linux. Processes are just running programs.
When the operating system starts up there is a process called init that brings up all the other processes on the system and lets you do work.
Subsequently started processes get a new process id that uniquely identifies them. We've already seen that the the python program we ran got a process id.

```
#check out
pidof init
```

this is a very interesting and controversial process in linux, especially now. We're going to study the init process in great detail later, but I'll give you some foreshadowing - there is a culture war going on right now as we speak about this first process started by the operating system. Some people say its too complicated, some people say it's too crude, some people say the NSA is spying on us via this init process - we'll talk about that later. In any event, its pid is 1, and all the processes started after it have a higher pid.

You can see a list of all your running processes with the very helpful 'top' command. There is another similar program called htop. Check it out.
exit top/htop by typing 'q'. In the top menu you can see the pid, the user who started the process, the memory and cpu usage of the process, the name of the command that started it, how long the process has been running and more. You already know how to get the pidof a running program by typing pidof program name. Start multiple python programs and then type pidof python, and you'll see a bunch of them. 

```
python program.py &
python program.py &
python program.py &
pidof python
100 200 300
```

Then it's up to you as a programmer to determine which one it is you're after! For example, if you want to write to the standardin of a particular program, youll need to know the pid of that particular program. Thats up to you as a skilled linux programmer to know how to get the pid of interest, and we're going to look at more tools to help you do that!

A job is a process started by a shell that doesn't detach. That is, it's there held onto by the shell. If you start a program in the shell, it's held onto by the shell. Do you know the computer science word for a detached process? Ten points for gryffindor if you know how to pronounce it right! This is just vocabulary you need to know - its a daemon process. The `jobs` command lists non-daemon processes! For example, type "jobs" - youll see the three python programs you just started. If you close your shell now, and then click the ssh button again, then type jobs again, youll see they aren't there anymore. Those processes / jobs were tied to your bash shell and when you closed it they all died.

Now here's a superuseful command. If you are running a numerical simulation, for example, and want to compute the value of pi, for example, you say

```
nohup python program &
```

Now type 'jobs' and you'll see its not there. There is more to be said about this, and if you come to office hours I can show you. The job is detached from you and stays running even when you leave the shell.

You can send commands to a running process to stop and start it if you want. You can switch the running programs from running in the foreground to running in the background.

But before we get ahead of ourselves, lets talk about something you are going to do every single day. This is essential, and we talked about it briefly in the last class when some folks asked about it, and I had to fight my urge to start talking about it so I just brushed it off.

Ctrl+Z is to stop a process, ctl+C is to kill it for good, to terminate it. Stopped jobs sit there and wait for you to start them up, killed jobs are done for good. Very important. Don't forget this! Lets look at a little example. There is a python script called "incrementNumbers.py" here, we will start it and put it in the background. First lets look at it and see what it does - the script will just write a number to the terminal every few seconds.

```
import sys
import time

x = 1
while( True ):
    sys.stdout.write("{}\n".format(x) )
    x += 1 
    time.sleep(2)
```

When we run the program with python incrementNumbers.py, well see that it starts periodically writing a number. We can sto pit with ctrl + z
Then when we type jobs, we see it is a stopped job. We can bring it back into the foreground with fg % jobid. Now we can stop it again with ctrl+z. Now we can send it to the background with bg %job id. The job will keep running, but now we have control of the terminal. but its periodically bothering us with its output. We can stop it again with kill -STOP pid or kill -SIGSTOP or kill -SIGTSTP . There are difference between these, but we won't go into it just yet. To see all of the kill signals have a look at `kill -l`.  To resume it type kill -CONT pid

As an experiment now, start a python incrementNumber process and let it get to 2. Then stop it with ctl + z. Then start another and let it get to 10. The start the first one with fg %1. Then stop it with ctrl + z. Then start the second one with fg %2. See how they pick up where they left off?

## [ 8:55 - 9:00 ] Break

## [ 9:00 - 9:35 ] More about processes.

----------ps---------------
Here is a real powerhouse for dealing with processes.
https://shapeshed.com/unix-ps/

ps gives the processes in the current shell. 
type

```
ps
```

then start a bunch of these increment number programs and send the output to /dev/null

```
python incrementNumbers.py >/dev/null &
python incrementNumbers.py >/dev/null &
python incrementNumbers.py >/dev/null &
python incrementNumbers.py >/dev/null &
python incrementNumbers.py >/dev/null &
python incrementNumbers.py >/dev/null &
ps
```
now you see all the processes associated with this shell
pkill python to kill them all at once. We saw some signals before like STOP and CONT, pkill sends the -SIGTERM signal which is signal  ( which number?? - ask class. remind to use kill -l) #15, and not the dreaded #9. More about these signals in a second, we already saw a few before but, as always, theres much mre to say.

now ps again
they are eigther gone, or reporting that they have been terminated.


To see all the processes running on your system type:

either 
`ps -e`
or 
`ps -aux`

to see processes by `user ps -u USERNAME`. For example, try `ps -u $(whoami)`

to see processes by group `ps -g GROUPNAME` - but whats a group?? We'll cover that in a few weeks.

Exercise:
How many processes am I running? 

ps -u melvyn | wc -l

How many root processes are running? 

ps -u root | wc -l

This is important information about running processes on your machine that can be used for all kinds of system administration tasks.

One more funny thing  I thought to do with the top command, talking about processes. Lets make a real resource hogging process and see it being greedy with top

```
while(True):
    pass
```

returning to our discussion about about the terminate signals, we saw two ways to kill a process. One was with CTRL+C before and now we say pkill program name ( which kills all instances of th eprogram). You can terminate a program with the kill signal with 

```
kill -KILL pid
kill -TERM pid
```

pkill sends the term signal, which is signal number 15. Ctrl + C sends the signal SIGINT, signal number 2. You may notice that if you try to Ctrl + C a program it doesnt respond. sigint tries to interrupt the process and says "excuse me, you should stop now". But sometimes you need to be more direct so you send the sigterm -TERM signal, signal number 15, as with pkill. But sometimes the process just wont listen so you bring out the bazooka and blast it with the -KILL signal, the dreaded number 9. How the process / operating system goes about handling these signals is interesting and will be discussed later if we have time to write a simple program to handle signals, but we probably wont have time. You'd need to grab a book on C programming and look into signal handlers.

https://gist.github.com/aspyct/3462238 Here is an example of a sample program that has signal handler logic in it. You can see that the programmer has written the program to behave in different ways depending on the signal it receives.


## [ 9:35 - 9:45 ] homework discussion.
