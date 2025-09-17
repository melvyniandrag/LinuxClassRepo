1. git config --list
2. git config --global core.editor "vim"
3. git config --global user.name "Melvyn Drag"
4. git config --global user.email melvyniandrag@gmail.com
5. git config --list

In this lecture we'll follow part of this book:
https://git-scm.com/book/en/v2

Nota Bene: This class has been somewhat deep, with lots of material brought up. Depending on how the class is responding and demonstrating knowledge of the class we will either integrate git or not integrate it into the homework.

# Git

## Introduction
there is alot to be said about git, but then again, very little. git is a version control software
whose use is pure and simple. Learning git takes you one step further to being a real, honest to goodness
Linux hacker. If you get a job working with linux, or you go to tech conferences, or you contribute to open source
software, you will be expected to know git! And that's why I'm here to tell you about it, and that's why you're hear to 
listen to me talk!

git is for taking snapshots of your software as it develops. You'll write a website, for example, and get all the code functional but then decide you want to experiment with writing some algorithm in a different way. So you snapshot your work with git, and then make your changes. If two weeks into making the changes you decide it was a dumb idea to write the code the way you did, git has a memory of the good version of the code, so you can download the good version again.

The problem it solves is that it keeps you from having to save your code in a mess of files on your pc. e.g. websiteV1.zip, websiteV2.zip, websiteV3.zip, alternateJSImplementation.zip, experimentWithNewCSSFramework.zip, and so on.

## Workflow

1. write some code
2. create a git repo
3. add code to repo.
4. change some files
5. add changes to repo ( repository ).
6. change some files
7. add changes to repo
8. etc.

## Class work

git is probably not installed on these machines

```
sudo apt-get install git
```


Then configure git. Let's look at our configuration file. 

```
user@machine$ cat ~/.gitconfig
#nothing. Maybe an error message about file not found.
```

So lets add some config options.

```
git config --global user.name "melvyn ian drag"
git config --global user.email "melvyniandrag@gmail.com"
git config --global core.editor vim
```

Now check out your config file again and you'll see we set some options for git. 


Now we will write some code.

```
user@machine$ mkdir myFirstRepo
user@machine$ cd myFirstRepo
user@machine$ echo "print(\"hello world\")" > script.py
user@machine$ python script.py # just make sure the script works.
```

Now we will create a git repo

```
user@machine$ git init
user@machine$ git add -A
user@machine$ git commit -m "my first commit"
```

now look in your directory with `ls -a`

```
user@machine$ ls -a
blah blah .git blah
```

Now lets look at the magic of git. Let's edit the file.

```
user@machine$ git status
All up to date
user@machine$ vim script.py
user@machine$ cat script.py
print("hi everybody!")
user@machine$ git status
    ...
    modified: script.py
    ...
```

And lets add a file too

```
user@machine$ echo "by" > script2.py
user@machine$ git status
    ...
    modified: script.py
    ...

    untracked files:
        script2.py
```

The repo has noticed that you changed a file, and it has also noticed the presence of a new file.
If you want to repo to keep track of the changes to a file you have to add it. The first time we added files we said
`add -A` to add all. Now we can run that again, or we can add the particular file with `git add script2.py`

```
user@machine$ git add script2.py
user@machine$ git status
```

Now we see that git has added the new file to file tracking. We should also add the changes we just made.

```
user@machine$ git add script.py
user@machine$ git status
```

To commit these changes to the repository, we commit the changes again! Notice that `git commit` takes a `-m` flag. All commits have to have a commit message attached to them. We said that the purpose of git

```
user@machine$ git commit -m "added script2.py and changed script.py"
user@machine$ git status
# all good.
```

Make a few more changes and get the flow down. Add some files, and change the ones that are there.

## The magic

Now to the magic of git - you can go back to a previous version of your code!!!

```
user@machine$ git log
# a list of all the changes you've made!
```

You can see the commits in a neater way with:

```
user@machine$ git log --pretty=oneline
```

you can checkout a previous commit using its hash. Git works on the basis of the SHA-1 hash - don't worry about the details yet, just file that away in your brain.

```
user@machine$ git checkout $HASHVALUE
```

Then look at the files - they will be as they were during that commit. As an example of this, I will checkout the first commit of the class repo. Let class see that my local copy on my machine changed. Do this for various commits to see how it worked. Let them see how the class developed over the last few weeks.

To go back to your current commit, just type

```
git checkout master
```

You can also tag commits. Generally, when you write software, you get to a point of stability that you are more or less happy with. You know when you have to download updates for things? The software writer wrote a successful piece of software, maybe with bugs in it, tagged it as v1.0, sold it to you , and then continues to update it and improve it. They may eventually get to v2.0 or v1.1 and then theyll let you update your software. That's the idea of tags. You can tag your own software.

```
user@machine$ git tag #lists your tags. There are none yet.
user@machine$ git tag -a v1.0 -m "version one with solid functionality, but some features lacking."
user@machine$ git tag
v1.0
```

This more or less is how git works. 

I told you that you can go back in time with git. This is a somewhat complex feature, so we'll postpone talking about it in too much detail.
Ill show you how to go back in time, but follow my instructions carefully, and keep in mind that there are a few juicy bits you need to learn before you can do this with 100% confidence.

Make some more changes, stage them, commit them, and tag them.

```
user@machine$ echo "x=1" >> script.py
user@machine$ git add script.py
user@machine$ git commit -m "added a variable to script.py"
user@machine$ git tag -a v2.0 -m "added a useless variable to script.py"
user@machine$ git tag
v1.0
v2.0
```

Now lets go back in time. This bit is tricky, so no funny stuff, okay?

```
$ cat script.py
#see the file contents
$ git checkout v1.0
$ cat script.py
#see old file contents
$git checkout master
$ cat script.py
#see the up to date file contents
$ git status
Up to date
```

What has happened here has to do with the git branching model, and we aren't going to go into that today. Try this a few times until you feel comfortable with it and see how useful it is.

## So what is "GitHub"???

So far everything has been happening locally on your machine, but you know there's more to the story! 
For the notes and assignments for this class I've sent you to look at files sitting out on a github server!
So there is a local aspect to git, and a server aspect to git.

You can use the server to backup your files - your code lives on a server so if your wife pulls your armpit hairs while you're working poolside on a hot summer day and drinking a cup of milk for breakfast and the whole 16 oz of milk spill all over you laptop and it dies - your code is safe on a remote server.

The server backup is also useful because it puts your code out in the wild for other people to be able to download it, look at the project history, modify it, etc. Notice how I'm keeping our course lecture notes and homeworks on github, regularly updating it, and you are able to read and download the materials?

We call the server a "remote"

Go to github and create a new repository now. 

Then follow the instructions to add a remote to the project youre working on. 
Then push to the server.
Then notice how you can see the commit history.
You can't see the tags yet, those go separately!

```
$ git push origin --tags
```

And thats it!

We can make a few more changes here on our machine, add/commit/push to the cloud, verify that the changes are on the server.

## Forking!

Now we will see how to fork repos. This a  concept on GITHUB - not on git. It's related to git, but I won't expect you to understand what goes on on the github server just yet when you click fork. Just fork and see what happens.

## Exercise
* I create a repo
* Everyone forks
* Then everyone clones to their machine
* Everyone adds a directory called MY_NAME
* Add a file called "aboutMe.md" to "MY_NAME" and put anything relevant about yourself. If you don't know what to say, just put something like "I like pizza" or "I don't like pizza"
* now add, commit and push to your fork
* Now back on github, make a pull request on my repo

## Adding collaborators
Show how to add a collaborator on github.

## How to sync your fork with the original. 
Sometimes the original will pass your fork. You will want to get in sync with the main branch.

Use this repo:
https://github.com/melvyniandrag/VexRiscv

and this 
https://github.com/KirstieJane/STEMMRoleModels/wiki/Syncing-your-fork-to-the-original-repository-via-the-browser

guide

SO Important, definitely go over this!

## Another example of syncing fork with the original
https://stackoverflow.com/questions/7244321/how-do-i-update-a-github-forked-repository

Try this  in class using a repo I create and allow the class to fork. Then make a change to my repo and make sure they can get the changes down to their computers.

## Conclusion

There are other version control softwares out there, like SVN(subversion), mercurial, surround but git is intimately tied to linux. You can read all the details in the homework reading assignment.

If you want to learn about SVN, you can check out a few tutorials I put on youtube which are to date my best videos ( even though they aren't perfect ).

I'm offline while I'm writing these notes, so I can't get to youtube, but you can go to youtube and look for melvyniandrag subversion or melvyniandrag SVN. If you like them, don't forget to like and subscribe!!!

## Extra 

Hacktoberfest-
show the mathtestmaker repo and the pdfmaker thing

Show how to contribute.

Remember, 5 prs = tshirt! Actually . . . you're going to get the shirt if you do the homework!!!

But still, contribute to my project if you want!!

https://hacktoberfest.digitalocean.com/

They might not give you a tshirt for "fake contributions" like we're doing in class. 

I'm not sure.


## if extra time
![home raspberry pis](Rpi.jpg)


Create a user name on homeraspby pi for a non-priv user
have everyon generate an ssh key pair
PUt the keys on the rpi for the non-priv user
Allow everyone to login
Show the 'who' command so everyone can see that they are all logged in to my machine. 

WIll the little rpi handle the traffic??!?!

Then remember to remove the keys, delete the user, and restart the machine
