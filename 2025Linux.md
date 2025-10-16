# 2025 Intro To Linux

## Course Goals
If you work hard and follow along with the lectures and assignments, at the end of the semester you will:
* Deploy a handful of websites on Linux servers
* Know how to use the Vim text editor like a professional
* Know how to do version control with git, github and gitlab
* Have a solid understanding of bash and shell scripting
* Know a bit about Python programming on Linux
* Know what a backend framework is and have experience with Django
* Know what a REST API is and how to make a website with a REST API
* Understand what containerization is and have a solid understanding of Docker
* Know how to use the Apache2 webserver
* Know what a reverse proxy is and how to use NGINX.
* Know SQL and have experience with sqlite3 and Postgres
* Understand essential system administration topics like managing users and storage

Each week you'll see a new topic, and it will build upon what you learned in the previous weeks.


## Overview

1. bash and digital ocean
1. bash and vim
1. i/o redirection, pipes, python, installing software
1. vimtutor, git, github
1. programming on linux in python, c++, more git
1. users, permissions, ssh
1. django and apache.
1. django rest API, curl
1. sqlite murder mystery. Play around with sqlite joins. Look at a django website and see that it is writing to the sqlite database.
1. postgresql. add to django site. After adding stuff to the db, inspect the data in the db.
1. file systems, disks, partitions, bash scripting.
1. docker and docker compose with a website. 
1. set up a gitlab server from scratch. set up a gitlab server with docker.
1. recap. vim, python, git, django, sql




## 1 - bash and digital ocean

## 2 - bash and vim

## 3 - i/o redirection, pipes, python, installing software

## 4 - vimtutor, git, github

### vimtutor
Work through the `vimtutor` tutorial to build on your vim knowledge

### git
Git is version control software. Discuss what version control is, and compare it to checkpoints in video games. Mention other version control software like svn, mercurial, etc. so students know git is part of a larger more important general concept "version control"
Then we'll learn what git is. We will spend an hour or so making repositories and exploring basic git commands. git is a huge topic, so we'll just focus on
* `git config --global user.name "your name"`
* `git config --global user.email "yourname@email.com"`
* `git init`
* `git add -A`
* `git add $filename`
* `git commit -m "your message`
* `git log`
* `git log --oneline`
* `git log --oneline --graph`
* `git branch`
* `git switch -c <branch_name> <commit>`
* `git switch <branch_name>`

### Github
After students demonstrate basic understanding of git, move on to Github. Make sure everyone has a github account.
Then we will push the repos we created up to github. Mention that we are only using https for now. In the future we'll see how to use ssh to simplify the process.
* `git remove add origin <url>`
* `git push origin master`
* `git remote -v`

## 5 - programming on linux in python, c++, more git
In this class we will build on what we already know. We will drill using vim to make python scripts, integrate the scripts into some pipes, and then drill using git and github.

First, make a new directory and add a python script that can write to stdout and stderr. Practice piping the output of our script to other linux commands.
Review I/O redirection with this python script. Then use git to make a repo and push our new repo up to github.

Then make a Python script that can read stdin. Practice integrating this script into pipes as well. Push up to github.

Then make a handful of Python scripts that can do other things
* for loops
* if/elif/else
* use print instead of sys.stdout.write
* make some functions

As we go on, students are forced to use their vim and git knowledge, while they brush up on Python along the way.

In the last 5 minutes of class have then
`apt install build-essential`
And then we'll write a c++ program that writes to stdout and stderr, and integrate this with pipes.

Then have them 
`apt install openjdk`
and we write a Java program that also writes to stdout and stderr.

This reinforces the idea that stdout, stderr are essential parts of using Linux, and they see that you can program in many languages on Linux.


## 6 - users, permissions, ssh

We start by looking at users, groups, permissions. 


### Users
Now on the droplets, have everyone add a user for themselves. Discuss adduser and useradd. See how there's a /home/user/you directory now.

Use `su` to login as your user. Make some files for your user.

Now see how to login as your user with ssh. Set up the `.ssh` directory so they can ssh in as a diff user, not root this time.

Then add a user for a classmate. 
Look how the users get a /home/user directory

Login as this user and make some files.

Note that they cannot login as this user over ssh, because you need your friend's ssh key. We'll do that later.

Then add a second user and see how theres a separate /home/user directory

Login as this user and make some files

Note that they cannot login as this user over ssh, because you need your friend's ssh key. We'll do that later.

### Permissions
Look at the permissions in `ls -l`. Play with `chmod` and octal permissions.

Play around with a python script and toggling the x permission so it's executable and not.

Make files for your user and see how you can play with permissions such that when you `su` to a different user, that user can't read or execute the file.

File permissions vs directory permissions
file r, w, x obvious

Directory Permission	What it lets you do
r	List file names inside the directory
w	Add/remove/rename files inside the directory
x	Enter and access contents of the directory

### git + ssh group activity
Students all pull down a git repo I made that will hold public keys.
Everyone will add a directory called `myName` and they have to put their public keys in the repo.
then push the changes up to github. This will be a mess, as they have to first pull, then push. They'll see how working on software as a team is a bit messy.
Hint about why "Pull Requests" are useful, but don't show them.

At this point I have a repo with everyones public keys.

Then have the students work with their friend from the previous activities and add the pub keys for those friends to the proper spots. Then they should be able to login to each other's droplets!!

## 7 - django and apache. Take the content from your what I learned in cs407 repo and make a website with it.

## 8 - django rest API, curl

## 9 - sqlite murder mystery. Play around with sqlite joins. Look at a django website and see that it is writing to the sqlite database.

## 10 - postgresql. add to django site. After adding stuff to the db, inspect the data in the db.

## 11 - file systems, disks, partitions, bash scripting.

## 12 - docker and docker compose with a website. 

## 13 - set up a gitlab server from scratch. set up a gitlab server with docker.

## 14 - recap. vim, python, git, django, sql
