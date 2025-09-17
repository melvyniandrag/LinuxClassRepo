# Setuid and Setgid

There are some special permissions that can be assigned to executables in Linux. You can trick your operating system into running a process as root, even though you are not root. The idea being, maybe you have a very trusted program that needs to do some root stuff. You are absolutely sure that the root stuff it does will not destroy your system, so you want to allow other users to do the root stuff even though they aren't root. <Flesh this out with some more discussion until it is clear>. 
  
A use case that I had was I wrote a very secure docker container and wanted anyone to be able to build and launch it, connected to a few system resources. I needed root permissions to make this happen, but I didn't want to drop into root all the time I wanted to do this safe thing, so I wrote a little program that would do some "rootly stuff", set the permissions and ownership of the file appropriately, and now I can run it as an unprivileged user.

If you call setuid(0) in your program, it changes you to the root user from the eyes of the operating system and lets you do rootly stuff.

## uid
In Linux, all users have a user id. You can get your user id from the command line by typing `id`. We haven't talked about this uid yet, and we certainly haven't used it, but it has been there all along. Today we will see what it is and we'll use it.

Try this:
```
$ id
[your id]
$ sudo su -
$ id
[you see user id is 0]
```
So now we know what the uid of the root user is. Check out this program:

We see that with this program we make a few calls to getuid() and a few calls to setuid(). You don't have to worry too much about this program - if you don't know C it will maybe scare you a bit. That's why I've chosen this simple and illustrative program.  The main idea is that you see some source code here that calls these mysterious functions getuid() and setuid()! We can change our user id while the program is running to trick the computer into thinking you are root!

`getuid` returns the user id of the user running the program.


We will first compile this normally and run it. You will see it fails and it exits with the value 1.
```
$ gcc setuid.c -o setuid
$ ./setuid
...
error msg
$ echo $?
1
```

To make this work, we will have to change the ownership, the group, and the permissions.

```
$ sudo chown root:root setuid
$ sudo chmod +s setuid
$ ls -l setuid
$ ./setuid
```

So you see that both user and group have an `s` where there used to be an `x`. This means that the program can setuid() and setgid(). For this example we only wanted to setuid(), so we can just set u+s.

```
$sudo chmod g-s setuid
$ls -l setuid
$./setuid
```

Notice if we make group have `+s` but take the privilege away from user, 

```
$sudo chmod u-s,g+s setuid
$ls -l setuid
$./setuid
[fails]
```

Also, rememberwhen we were setting permissions using the octal notation? You can do that for this as well. There is no setAllID, there isonly setuid and setgid
So set uid is a 4, setgid is a 2, but what does the 1 correspond to? Not a big deal, I'll leave it here for you to read if you're curious! https://askubuntu.com/questions/432699/what-is-the-t-letter-in-the-output-of-ls-ld-tmp . So getting back to octal numbers and setuid/setgid we can set the permissions to r-sr-xr-x by saying `chmod 4555`. We can set the permissions to `r-xr-sr-x` with `chmod 2555`. Etc.

## A simple reference:
https://www.adampalmer.me/iodigitalsec/2009/10/03/linux-c-setuid-setgid-tutorial/

but this reference is flawed. Here is more reading to go more in depth!

https://stackoverflow.com/questions/7656549/understanding-requirements-for-execve-and-setting-environment-vars
https://stackoverflow.com/questions/36673765/why-can-the-execve-system-call-run-bin-sh-without-any-argv-arguments-but-not/36674366
https://stackoverflow.com/questions/2794150/when-can-argv0-have-null
https://unix.stackexchange.com/questions/187666/why-do-we-have-to-pass-the-file-name-twice-in-exec-functions
https://stackoverflow.com/questions/17785983/ruid-euid-after-exec
https://jameshfisher.com/2017/02/05/how-do-i-use-execve-in-c.html
http://www.cis.syr.edu/~wedu/Teaching/cis643/LectureNotes_New/Set_UID.pdf

