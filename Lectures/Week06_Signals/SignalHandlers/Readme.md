# Signal Handling in Linux

## Introduction
In this class we're going to look at signal handlers.
We already saw that we can send signals to a process with a 
keyboard. Specifically, we can send the `SIGINT` signal to a process
with `CTRL+C` which aborts a process, SIGINT can cause a process
to end completely.

We'll use this simple process as an example:
```
$ cat program.py
import time
while True:
    time.sleep(1)
$ python program.py &
[PID]
$ <TYPE CTRL+C>
#Process exits
```

We can also send the `SIGTSTP` signal to a process with `CTRL+Z`

```
$ python program.py &
[PID]
$<TYPE CTRL+Z>
#process stops
```

These stopped processes can be restarted by sending them a CONT signal.

## The kill Command
You can use `kill` to send a signal to a process. For example, to make
a stopped process resume execution.

```
$ kill -SIGCONT $STOPPEDPID
```

You can see all the signals you can send by typing `kill -l`. You can send these signals in three ways - you can type the signal name, the signal name prefixed with `SIG`, or you can send the signal number. 
For example, to send the CONT signal you can send:

1. `SIGCONT`
2. `CONT`
3. `18`

In this lecture we're going to focus on `SIGINT`, `SIGKILL`, `SIGTERM`, `SIGSTOP`, `SIGTSTP`, and `SIGSEGV`. In particular, we're going to look at when you should use each one, and 
how programs handle the signals when they are received! These are 6 of the most interesting of the 64 signals shown by `kill -l`, and they serve to illustrate key points about signal handling.

We'll play with the signals a little bit more before we start coding.

```
$ python runForever.py &
[pid]
$ jobs
[1]+ Running     python runForever.py &
$ kill -20 %1 # kill takes pids or jobs. You could also put the [pid] from above
$ jobs
#stopped
$ kill -18 %1
$ jobs
# it's running again
```

We just sent SIGCONT and SIGTSTP. We can also send a signal related to TSTP called STOP.

```
$ python runForever.py &
[pid]
$ jobs
[1]+ Running     python runForever.py &
$ kill -SIGSTOP %1 
$ jobs
#stopped
$ kill -18 %1
$ jobs
# it's running again
```

SIGSTOP cannot be ignored. SIGTSTP can be sometimes. SIGTSTP comes from the keyboard. You send SIGSTOP from a program.

## SIGINT, SIGTERM and SIGKILL
`INT` is sent when you hit `CTRL+Z` on your keyboard. It interupt the process and makes it stop. `SIGINT` can also be sent will `kill`. `SIGTERM` and `SIGINT` are approximately the same thing, differences in their behavior are left up to the application developer. You should now send `INT` and `TERM` to the `runForever` program and you will see that both end the process. 

We will change the behavior now. Open `01*.c` on your computer and have a look at it.
This is a small C program that registers two signal handlers

## SIGSTOP and SIGTSTP

## SIGSEGV

## What are signals?
Signals are a form of interprocess communication used in Linux. There are many interprocess communication mechanisms, this is just one of them. If you've never heard of IPC, just know it is all around you when you are using computers. For example, consider the case when you are on your telephone and you're listening to music. When a phone call comes in, the music is probably paused and the phone app is brought up on the screen. The operating system on your phone needed an IPC mechanism to detect that the phone process was in some active state and that other interfering processes need to take action while the call is active. Depending on how the software is written on your phone, the music might resume playing when you hang up, and the music app might come to the foreground on your screen. Or maybe it stays paused and you have to manually reopen the app and hit 'play' again. Or maybe something else happens.

IPC might also be used if you have two processes on a device - maybe you have one process listening for radio transmissions and another on that turns a motor. If the radio receiver receives a signal, maybe you want another process to turn a motor and open your garage door or something.

There are many ways to do IPC, even on Linux there are a bunch of IPC mechanisms. Signals is just one of them.
