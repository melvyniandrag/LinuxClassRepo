## 6 - users, permissions, ssh

We start by looking at users, groups, permissions. We



### Users

Create a user

```
root@machine$ adduser melvyn
... do the stuff
root@machine$ ls /home
... now there is a melvyn directory!!
root@machine$ su - melvyn
melvyn@machine$ exit
root@machine$ do this a few times to switch users.
```

Then  create a different user.

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


```
| Letter | Number | 
| --- | --- |
| r	| 4 |
| w	| 2 |
| x	| 1 |

```

2 Basic file types: 
- binary
- executable

| File Permission	| What it lets you do | 
| --- | --- |
| r	| Read a file. e.g. cat file, vim file |
| w	| Modify the file.  |
| x	| Execute the file  |

Executable files:
1. binaries such as `cp` or `mkdir`, or even your own binaries that you compile with g++, etc
1. scripts with the shebang line

```
/usr/bin/python3

print("hi")
```

or

```
/bin/bash

echo "hi"
```



| Directory Permission	| What it lets you do | 
| --- | --- |
| r	| List file names inside the directory |
| w	| Add/remove/rename files inside the directory |
| x	| Enter and access contents of the directory |

Notes:
To ls a directory you need r and x bits.


### git + ssh group activity


Students all pull down a git repo I made that will hold public keys.
Everyone will add a directory called `myName` and they have to put their public keys in the repo.
then push the changes up to github. This will be a mess, as they have to first pull, then push. They'll see how working on software as a team is a bit messy.
Hint about why "Pull Requests" are useful, but don't show them.

At this point I have a repo with everyones public keys.

Then have the students work with their friend from the previous activities and add the pub keys for those friends to the proper spots. Then they should be able to login to each other's droplets!!

### Going further
Not only are there permissions on files, but there are additional ways to control what can be done to files and directories and by who.

These additional things you can do depend on the file system on your storage device.

Looks have a quick look at attributes. These work well on the ext4 file system.

```
root@machine$ echo hi > hi.txt
root@machine$ chmod 777 hi.txt # now anyone can do anything to this file... right?
root@machine$ lsattr hi.txt
look
root@machine$ chattr +i hi.txt
root@machine$ rm hi.txt 
Not allowed!!
root@machine$ lsattr hi.txt
look
root@machine$ chattr -i hi.txt
root@machine$ lsattr hi.txt
look
root@machine$ rm hi.txt
```

These file attributes will not work on all file systems. A fun learning experiment for you one day would be to look into different file systems
1. ext4
1. ext3
1. ZFS
1. btrfs
1. xfs
1. FAT
1. HAMMER2 (only on Dragonfly BSD)

What sort of restrictions can you put on files on these various file systems?

If you are going for a job as a sysadmin or to work in cybersecurity, you ought to have a look into SELinux.