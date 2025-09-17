# The Filesystem Hierarchy Standard.

The filesystem hierarcy standard. Specifies some standard directory layout for Linux systems. 

Look at

```
man hier
```

Some examples for each directory:

/ - look at all the directories. Suggest starting instances of multiple distros in the vm to see how they are the same.

/bin - programs needed for single user mode, for bringing a system up in maintenance mode. I've never had to do this for maintenance, but the utilities it provides are simple standard commands like `cat`,`ls`, etc.

/boot files to be used for booting the system. These are low level things you won't worry much about as a general desktop user, application developer, or web programmer. This is lowlevel stuff for getting the OS up and running between the time you plug it in and hit the power button and start using Linux. You'll see the Linux kernel, the bootloader (on your system youll probably see grub, but on an embedded project you'll probably see uboot. ) We'll compile the kernel in this class and maybe poke at the bootloader, but it might be more instructive to poke at the bootloader of a physical pc sitting in front of you.

/dev - devices and things. you'll see your harddrive/sdd for example as something like /dev/sda. There are a bunch of ttys. What a tty is and how you use it is of particular interest to me, and maybe during office hours Ill show you some stuff I do with those devices.

/etc - config files. We already configured ssh last week by messing with a config file in here.

/home - user home directories. Your homework will be to put this on a separate physical drive. This is where users put their data. Photos, downloads, video games, etc.

/lib - libraries for booting the system and used by programs on your computer.

/lib<qual> Youll see 32 and 64 bit variants of the various libraries. If you don't know what "dynamic" vs. "Static" linking means, and have never used static vs dynamic libraries, this will be outside of your understanding.

/media - where auto mounted media goes. When you stick a usb stick in, or a CDROM, it will generally appear here.

/mnt - where you will manually mount filesystems for your use. We'll explore some use cases of this today.

/opt - a place for "add on packages". Stuff you want to install goes here. The use of this directory is debatable and I leave it up to you to decide what you put here and what philosophical stance you choose on what ought to go here.

/proc - we already looked at this when we looked at stdin/stdout/stderr. We'll revisit that quickly. Write a little python program:

```
while True:
    pass
```

Run it in the back ground

```
user@machine$ python program.py &
[outputs pid]
user@machine$ ls /proc/$pid/fd
0 1 2
\
```

you see the file descriptors for stdin, stdout, stderr. the /proc has information about running processes. There is much more to see besides the file descriptors, but thats the only example I'm going to provide.

/root - the home direcotry for the root user. The root user doesn't get a directory in /home.

/sbin - programs for booting and maintaining the system, but not used by regular users. https://ma.ttias.be/understanding-the-bin-sbin-usr-bin-and-usr-sbin-split/ 
http://landley.net/writing/hackermonthly-issue022-pg33.pdf

the difference between sbin and bin has history behind it, and I've linked a few quick and interesting reads explaining the differences.

Do take a moment to 

```
ls -l /sbin
```

 and notice that many of the commands there are actually links to the commands in /bin. What's a link? In general it's like a windows shortcut. The actual program isn't in /sbin, it's in /bin, but when you call the one in /bin, it calls the one in /sbin. `bash` isn't linked, however, bash is in /bin you'll see. 

```
$ which bash 
/bin/bash
$ ls -l /sbin/b*
# bash is not there
```

doesn't matter, just showing you.

/srv - I haven't ever used this. It might be relevant to you, I don't know

/sys - don't worry about it

    /tmp - temporary files. Depending on the distro you use these might or might not be deleted on reboot. They might be cleaned up before reboot. They are temporary files, and the longevity and uses of them differs and depends on you.

For example, 

```
ls /tmp
# some stuff about ssh
```

that's temporary info about your ssh login. Don't worry about the details. 

/usr - another location for executables, libraries, etc, typically read-only stuff that isnt essential to booting the system. There's alot of argument about what goes in here. If you're a sysadmin or linux application developer you will work on this.

Notice that tmux isn't essential to your system. 

```
$apt-get install tmux
$which tmux
#/usr/bin/tmux
```

If you want to feel confused for a bit, look at this post:


https://unix.stackexchange.com/questions/8656/usr-bin-vs-usr-local-bin-on-linux

people discuss the uses of /bin, /sbin, /usr/bin, /usr/sbin, /usr/local/bin, ~/bin, etc.


It hasn't mattered to me in my career what goes where, but depending on the depth you go into Linux you may develop a passionate opinion.


## If time

Read the sbin/bin article together.

http://landley.net/writing/hackermonthly-issue022-pg33.pdf
# An aside - A beautiful Thinkpad + Linux setup seen on Reddit
https://www.reddit.com/r/thinkpad/comments/arb27u/between_humanities_and_technologies/

Here's a person running Linux, compiling KDE and firefox while working on an english paper and studying cyrrilic.

# Drives, Partitions, Mounting, and Partitioning.
The idea of this part of the lecture is that sometimes you want to add storage space to your machine. You might have a 250GB SDD and you just bought a 1TB drive and you want to add it to your machine so you can download more movies, save more pictures, store more code, whatever.

## Look at what storage space you already have.

```
$lsblk
sda      disk
--sda1   part
```

sda is a physical drive on your computer, like a harddrive connected to the machine. sda1 is a partition of the drive, it's a chunk of memory you 
formatted in a particular way to become useable by your machine.

## Now we will add another drive

Read this: https://cloud.google.com/compute/docs/disks/add-persistent-disk
On your vm instance page click the instance name
click edit
click add item
click to add disk 1, by default 500GB disk
click save

now do this again
```
$lsblk
you have a drive called sdb now!
```

google cloud gave you a partition too. Note that this is different from the normal experience, there ought not be a partition there. We could have tweaked the partitioning too before adding it. Let's see that in action. Now we'll add an unpartitioned disk.

click add item as before, but this time in the drop down click "create disk" and create it, then save it 

now when you 

```
$lsblk
# theres an unpartitioned disk called sdc ( or something else! )
```

Windows normally gives your drives names like 'C:/', 'D:', 'E:', right? I'm not a Windows expert but I know that this is what it looks like on a Windows computer.


# Looking at Partitions, Partitioning and Mounting

## Introduction

Lets look at the two drives we added, the one had a partition on it, the other one didn't. What does that mean??

lsblk -h shows us options for showing information about our drives. There's alot to take in. Let's focus on this command:


## gparted


If you weren't in class, here's a good reference to get you started

https://www.digitalocean.com/community/tutorials/how-to-partition-and-format-storage-devices-in-linux

You may notice that drive sda is 10G and the partition sda1 takes up the full 10G, whereas sda2 takes up only 4XX GB of the 500GB on the disk, and then sdc is a 500GB drive with no partition. There are some weird things happening here and I'm going to explain the basics to you.

We are going to format and add some space to our machine under /mnt, just to do it as an exercise.

```
sudo parted /dev/sdc mklabel gpt
sudo parted /dev/sdc mkpart primary ext4 0% 100%
lsblk
# now its there
sudo mkfs.ext4 /dev/sdc1
sudo mkdir -p /mnt/newdrive
sudo mount /dev/sdc1 /mnt/newdrive
lsblk
# now the partition is mounted
lsblk --output  NAME,FSTYPE,SIZE,MOUNTPOINT
```
You can also unmount the drive

```
#sudo umount mountpoint
sudo umount /mnt/newdrive
```

## Again step by step

```
sudo parted /dev/sdc mklabel gpt
```

We first label the disk. This layouts the structure of the disk. There are other names for the label - partition table and partition map are other names. The disk has some metadata about the partitions it contains and how they are structured, that's what this is for. You will mainly be interested in mbr/msdos or gpt partition tables. There's plenty to be said about mbr vs gpt partition tables. If you want to leave class knowing something, though maybe not understanding it fully - MBR is good for drives up to 2TB. Past that you need GPT. GPT is associated with UEFI whereas MBR is associated with BIOS. If you're confused, keep studying. In the meantime, just use gpt on Linux.

```
sudo parted /dev/sdc mkpart primary ext4 0% 100%
```

This command puts a partition on the labeled disk. The partition can be extended/logical or primary. For us we will make a primary partition. We also tell parted what file system type we are going to put in the partition. We will use ext4. There are many file system types, and you can read in depth about them if you're interested. ext4 is "the best file system type in Linux" in some senses, and not as good as file system types in other senses. It's up to you how much you want to know. Here's a reference to get you started:

https://opensource.com/article/17/5/introduction-ext4-filesystem
https://askubuntu.com/questions/44908/what-is-the-difference-between-ext3-ext4-from-a-generic-users-perspective

We also made the partition start at 0% and go all the way to the end of the drive.

```
sudo mkfs.ext4 /dev/sdc1
```

This puts the ext4 filesystem on the partition you created.

```
sudo mkdir -p /mnt/newdrive
```

create a mount point for your new disk. You can put it in mnt for now.

```
sudo mount /dev/sdc1 /mnt/newdrive
```

Now mount your disk. 

You can see it with 

```
lsblk
```
or also with

```
df
```

Now mount/unmount the drive a few times to check it out.

Add some stuff to the partition, unmount it, remount it. see stuff is still there.

unmount it and mount it somewhere else. 

see the stuff you created is still there under the mount point.

## restarting machine makes this go away

```
sudo reboot
#new terminal
lsblk #mounted disk not there anymore.
```

to make the disk permanently mounted, update /etc/fstab

add this line to the file:
```
#part     mnt point fstype ignore ignore ignore
/dev/sdc1 /mnt/data ext4 defaults 0 2
```

Here's a good reference. It explains what the last three parameters are. Not relevant to us now, but they are important. We won't discuss them because that would take us off track.

https://help.ubuntu.com/community/Fstab


TO SEE that it is now mounted even after reboot, reboot your machine!

```
sudo reboot
```

Log back in and see the partition is present.


## Move opt to separate partition

```
mkdir ~/opt_backup
cp -aR /opt/* ~/opt_backup  
sudo mount /dev/sdc1 /opt
lsblk
```

Note that /dev/sdc1 is not mounted at /opt. Notice that the contents of that partition are now visible under /opt.

Unmount the drive. Put some stuff in /opt. Remount the drive. Notice that the stuff you put in opt are hidden, but the drive stuff is there. 
The stuff is still there, if you unmount the drive you will see the files there - but when you mount the partition there those files are hidden by the stuff in the partition.

There may be ways to change this behavior, but that's not the way Linux works. 

# fdisk
There are many tools to use when partitioning disks. I like parted best - or gparted is best if you have a Desktop GUI! There is also fdisk, an older and oft used tool for partitioning.

Instructions on how to use it.
https://www.crucial.com.au/blog/2009/11/18/how-to-create-a-new-partition-on-a-linux-server/

Make sure your /dev/sdb1 is unmounted.

```
sudo fdisk /dev/sdb1
d ( delete partition )
n ( new partition )
follow instructions
p (view the part)
w (write the part)
```

Run
```
lsblk --output  NAME,FSTYPE,SIZE,MOUNTPOINT
```

To see there is no filesystem on the partition.

Then lets put a file system on the disk. If you want to try and mount it now, you'll see an error, the system expects a file system type there.

```
#If curious
sudo mount /dev/sdb1 /home/melvyniandrag/mntpoint
#error
```

So we'll put a file system on there.

```
mkfs.ext4 /dev/sdb1
mount the partition in a few places. Add files. Unmount, mount somewhere else, see the files are still there.
```

##Etc.
You may have noticed that with parted we specify a file system type when making the partition. That isn't essential, it's optional. See the documentation:

https://www.gnu.org/software/parted/manual/html_node/parted_19.html
How to move your home directory.
# The PATH enviroment variable

Enviroment variables store information about the current environment. I've already shown you ways to affect the visibility of environment variables and the effects they have on your environment through the use of `export`. 

One of the well-known and frequently modified variables is the PATH variable. In general this changes which executable programs are accessible by your current environment.

You can 

```
$echo $PATH
/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games
```

These are the locations of the executables that are easily visible in your current environment. Notice that the path is separated by colons. That's just the way it's formatted. What are some executables you have been using in this class?

1. md5sum
2. cat
3. ls
4. mv
5. cp
6. vim
7. accept other class contributions.

Type `which` and the program name for any one of these and you'll see that it is in one of the PATH directories.

e.g.
```
$which vim
/usr/bin/vim
```

You could also type `/usr/bin/vim` and it would work, but since it's in your PATH you don't need to specify the full path to vim. You can try that with other programs we're using too! e.g. `which cat`, then type the full path it gives you and you'll see it runs the same. 

You can make a custom executable program, e.g.

```
#!/bin/bash
echo "hello world"
```
save as program, chmod to 777, and then type "program" - it won't run! but you can type /path/to/you/program and it will run. It doesn't run by you just providing the name because it isn't in your PATH.

## Changing your PATH
You might want to change your path at times to make programs you write  visible. To drill the concept home of PATH visibility, copy your program to a location in your path.

```
$mv hello /usr/local/games
$hello
hello world
```

but now let's change our path so that the program is visible without having to move it to somewhere in your path.

```
# move hello program to /opt
# add export PATH=/opt:$PATH to the .bashrc file
$which hello
/opt/hello
```

So that's how you change your PATH, and that's what the PATH is all about. The are other syntaxes for changing the PATH and other means to do it, but this will suffice for us for now.

## Ordering of stuff in your PATH
What is the resolution for stuff in your path?

# Binary vs. Executable ( A Vocabulary Lesson )
The expressions "binary" and "executable" are used interchangeably in Linux circles, but they don't always mean the same thing. And ".exe" in windows in an executable file. A file with x permission is executable. When people refer to a binary/executable they generally mean a file that is compiled into a binary format that the machine can read and run. Like "cat" is a binary file. If you 

```
vim /bin/cat
```

you'll see its a  mess, it's a binary file that's compiled to be read b y a computer, it's not a text file that a human can read. Thats why when you look at it with vim you see unreadable junk.


