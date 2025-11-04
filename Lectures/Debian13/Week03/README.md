# review, programming, and git/github

## programming on Linux
You can write programs on Linux. In this class we'll talk about python and C++ because these are two of my favorite languages, but you can program in any language you want on Linux.

### python
1. install
2. write and run hello world
3. write a program that writes to std out
3. take that program and pipe it's output to grep
3. make the program write to stderr. note that grep does not filter out the junk, because pipes only work on stdout.
3. write and run a program that will run forever. kill it with ctrl C

### C++ 
do the same as the above, but do it with C++.

## git
Now we move on to git. There are 3 terms floating around in this class and we should get some terminology correct.
1. git - a version control system created by Linus Torvalds, creator of Linux. There are many version control systems such as git, mercurial, svn, surround, and so on. They all behave differently and have different design philosophies and commands. git is the most popular version control software used today.
2. Github - a website that hosts your git repositories. You use the git program on your local computer, but you can back up your data remotely on Github. There are other sites that do the same thing, such as bitbucket or gitlab. In fact, later this semester we'll see 2 ways to create your own git server.
3. git bash - this is a program that the Windows users in this class have installed. This is a bash shell for windows that allows you to do all the shell things you do in Linux on Windows. MacOS is a type of Unix, and by default mac OS comes with zsh installed. zsh is quite close to bash. And you can install git on mac OS and use it just like you do on Linux or in git bash ( that's why the mac users dont need to install git bash). Windows comes with it's own shells - CMD and Powershell. But these don't behave like bash and we won't focus on those in this class.

## Let's learn git.
commands to master:
* git init
* git add
* git commit
* git switch 
* git restore

install git. 
create a repo.
put some code.
add
commit.
do a few more times.
then check out your logs.
then start a feature branch and implement a different feature.
break the code base. Note that master is unaffected.
fix the feature. 
merge into master
now we have details commit information about the work we've done on our project. What happens if we lose our laptop though?

## github
github is for backing up your git repo. Look at the .git directory in your repo. This holds all of the information about your project history. You can back this up for multiple reasons. 
* in case your computer breaks, its nice to have a backup
* if you work on a team, you all can work on this repo together. git is "distributed version control". Everyone can have a local copy and you can all push changes to a central location to share them.

create a repo on git.
push our local work up to github.
note that there is only one branch on github. checkout your other branch locally and push that one up too.
note that were using passwords and passwords are annoying... but we already know a way to login to servers without passwords! SSH!
put your ssh pub key on github.



