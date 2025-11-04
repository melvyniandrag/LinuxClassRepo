# SSH and SFTP
By this point in the semester you've been using ssh quite a bit to connect to your droplet. You
should know how to use ssh and sftp to get files onto your computer. In this lab we will play with
ssh and sftp so you know how to get files to and from a droplet 

## SSH Configuration
Up until this point, we've only used ssh to connect to our droplet.

Connect to a droplet using ssh, and now we will see how to connect with a password.

Login to your droplet and then use vim to inspect

`/etc/ssh/sshd_config.conf`


## What is sshd?
`/etc/ssh/sshd_config.conf` is the sshd configuration file. Wait - what is sshd? Isn't it ssh?

*ssh is the client, sshd is the daemon that runs on the server*. You use ssh on your client to
connect to a computer that's running an ssh daemon aka ssh server.


You will see in this file that there is a line to include `/etc/ssh/sshd_config.d/*`

## Whats innside sshd_config.d?
The files in this directory are additional config files.

The configuration file can pull in additional configuration files. If you look in
`/etc/ssh/sshd_config.d/` you will see the file(s) have a number in the beginning like 
`50-myconf.conf` 

This is because ssh will read these in in sorted order and assign values to variables. ssh will save
the first match it sees.

### Activity 1
Add a user to your computer `adduser test` and give a password you can remember. Accept all the
other defaults.

Attempt to ssh in like `ssh test@ipaddress`. You will not be able to, because password
authentication is off. Inside the config file in `sshd_config.d` you should have seen that password
authentication was no.

In that conf file, turn on password authentication. Add a line ( or modify an existing line ) and say 
`PasswordAuthentication yes`


Then run `service sshd restart` or `systemctl restart sshd` and then try to ssh in again like `ssh
test@ipaddress`. This time it will ask for the password and you will be able to get in.

Once you've gotten this to work, move on.

### Activity 2

Turn off password authentication in the file in `sshd_config.d`, and turn ON password authentication
in `/etc/ssh/sshd_config.conf`. 

Then restart sshd.

Attempt to ssh in as the test user. You will not be able to.

Remember that sshd reads the config files and saves the first match it finds. In  the config file
`50-.....conf` we turn off password authentication, and we import that in the top of
`/etc/ssh/sshd_config.conf`, so even though you turned on password auth in that file, it was already
set in the imported file.


### Activity 3
Let's drive the point home.

1. Turn OFF password auth in `sshd_config.conf`, 
1. turn it ON in 01-myconf.conf, 
1. and turn it OFF in 50-conf.conf. 

restart sshd.

Are you able to ssh in as the test user? You should be able to , since 01 is read before 50 and
before the line in the main conf file. 

## SFTP
SFTP is the Secure File Transfer Protocol. It's a super useful tool for putting files on a server
and getting them off. In this exercise, we will get files off of the droplet, and put files onto the
droplet.

### How SFTP Works
SFTP works alot like what you're used to in the shell, but
1. It has a limited set of commands
1. It has 2 versions of each command - a *local* one and a *remote* version.

The *local* version of the command runs on the machine that you are sshing *from*. The *remote*
version of the command runs on the *remote*.

Sftp into your droplet like

`sftp root@droplet`

Now you can use the following familiar commands on the remote:
1. ls - list files and directories on the remoe
1. cd - change directory on the remote
1. pwd

But unlike ssh, you can also run local versions of these commands like
1. lls - local ls
1. lcd - local cd
1. lpwd - local pwd

You can navigate to where you want to on the remote, then navigate to where you want locally, and
then you can get files from the remote and put files on the remote.

### Be careful!!
Note that you cannot use all of shell commands and linux utilities that you know when youre
connectetd with sftp. Sftp offers a limited set of tools that allow you to get and put files from
and to the droplet.

This might confuse you at first. When you sftp into the droplet you will see a cursor that looks
when you connect with ssh, but it's different. sftp only allows you to do a few simple things.

### Put a file on the droplet
1. Open a gitbash terminal on windows or a terminal on mac. 
1. Use vim to create a poem file

```
roses are red
violets are blue
```
1. Now connect to your droplet with `sftp root@ipaddress`.

1. You use the *put* command to put files on the droplet.
1. use lcd to go to the location where you saved your poem.
1. use cd to make sure you are in `/root` on the remote.
1. `put poem.txt`
That's it!

### Try again with another file.
Can you create another file locally and upload it to the host?

### Try again with another file.
Can you create another file locally and upload it to the host?

### Get files from the droplet
Can you get each of the files from `/etc/ssh/sshd_config.d` to your desktop on your laptop or pc?

Use sftp to connect to the droplet. Then use cd to navvigate to `sshd_config.d`. Then use lcd to
navigate to your desktop. Then use *get filename* to get the file to your computer from the droplet.

### Try again!
Create a file on your droplet and get it with sftp.

### Get a tarball from the droplet!
Tarballs are popular ways to share bundles of files. Create a tarball on your droplet and then get
it to your local machine.

To create a tarball

```
mkdir myDirectory
cd myDirectory
# then use vim to create a bunch of files
cd ..
tar cvf mytarball.tar myDirectory
```

Then use sftp to get the tar to your computer.

## Put this info to good use.
Now let's exercise what you learned.

Currently you can only connect to the test user with a password. But this is no good! We prefer ssh
keys!!

1. turn on password access to your droplet.
1. Use sftp to put the .ssh/id_rsa.pub from your computer onto your droplet. 
1. Make sure you put this file (your pub key) at the end of the file
   /home/test/.ssh/authorized_keys.
   1. The permissions on /home/test/.ssh should be 700
   1. the permissions on /home/test/.ssh/authorized_keys should be 600
   1. The ownership  should be test:test. Be sure to chown -R test:test /home/test/.ssh
