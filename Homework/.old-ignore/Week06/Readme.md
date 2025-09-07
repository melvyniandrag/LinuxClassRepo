# Homework 6:

## Problem 1
Compile, change ownership, change permissions, and run the execve_setuid program we looked at in class. All you need to do is repeat what we did in class. I just want to know 100% that you have made compiled and run a setuid program before. 
 
## Problem 2
Get the "states" game from the 12/ directory here: https://github.com/brandonprry/wicked_cool_shell_scripts_2e
Make the code work. It uses a tool "randomquote" on line 23. "randomquote" is
available in the 8/ directory of that repository. Also, it requires a data file
that can be downloaded in the git repo as well. There is an error in the script
that tells you to download a file from intuitive.com or something, but the file
is not there. The file is there in that github link I sent you. I don't know
what all else may be required to make the code run. I know it's not too hard so
I'm just assigning it as homework. 

The main challenge, after getting the script to work:

Add some signal handling to the bash script so that CTRL+C does not stop the process. 
We didn't cover bash signal handling in class Instead we covered signal handling with C. In bash it is even easier. Make 
sure to read this: https://www.linuxjournal.com/article/10815

As I mentioned, if the 

# Problem 3
Install `cowsay' on your machine and make it say something. Figure out what
cowsay is and how to use it. Look on youtube for cowsay, a million results will
come up.

## Submission Guidelines
Due: Before 7:00 PM on March 3rd. Fork and pull request the class repository. 
Include your files under Homework/Week06/StudentSubmissions/YourName

Do the PR correctly or I'll reject it! I need the format to be precise to make sure that you don't ruin the repo.

Grading:
33% The setuid/setgid program can be run as an unprivileged user to do some privileged action.
33% Game works, and ignores CTRL + C.
34% You can ssh into a digital ocean machine.

Submission:

For credit upload three images and your game code for problem 2.

For image 1 I want you to run:

Image 1:
```
$date
$gcc execve_setuid.c -o example
$sudo chown XX:XX
$sudo chmod XXXX
$whoami
$./example
[output]
```

Image2:
```
$whoami
$./states
[play a little bit]
$CTRL+C
[Should see a message that CTL+C was ignored]
[play a little bit more]
```

See sample images for an example of a good submission.

Image3:
Screen shot showing you connect to a digital ocean server:

```
user@machine$ # do something with cowsay and show me.
# bonus points if you can make an animal besides a cow say something.
```

Thats a total of 4 files.
