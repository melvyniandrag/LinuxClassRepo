# SSH + SSHD + SFTP Lesson Plan 
1. Intro to class... Look at the class assignments up until now... A lot of information about multithreading, and how the OS works.. thinks like fork(), clone(), exec()... low level things like threading and memory management, processes. That is definitely useful stuff that explains how the OS works and shows that the other professor approched this class in a different way from how I approached it. I like to teach hands on things that get you hacking from day 1, the other professor was doing that - really well I think! I came in and alot of you knew the basic commands I was showing last week! But I usually wait a while before showing the gory details of how the OS works. We will certainly do that though. 

The other prof was talking about Solaris which shows he has a different history of using Linux than me, maybe he worked on old enterprise systems in banks or something. Ive never used Solaris, its a linux for businesses and I think its dying and being replaced by linux everywhere. Anyway it doesnt matter, all the nixes are quite similar, but there are differences in 
1. The gory details of how things ACTUALLY work in the C code. But the user experience is usually quite similar if youre on debian, ubuntu , solaris or mac os or freebsdf
2. They also differ based on the versions of the utils on the machines so you'll have to type commands slightly differently on each one.

Oh, but the professor was using a js emulator linux. This is cool, but  I prefer to get you on a real production machine that we have more control over. Why? Well the internet went down the other day... 

A cloud computer is a someone elses computer.
A cloud computer is a someone elses computer.
A cloud computer is a someone elses computer.
A cloud computer is a someone elses computer.

In this class I want you to know all about how to use linux.
My dream is that you will go out and buy your own linux comptuer and use it everyday and join the fight against corporate control of computers.


1. First create a droplet that allows only ssh key login and explain to class what ssh is and that it can use keys or passwords
1. Connect to the droplet and ask students to try to login. It wont work because they dont have keys on the machine
1. Enable passwords by editing the file in `/etc/ssh/sshd_config.d/*.conf`
1. Then `service sshd restart`
1. Then change the root password to cs407
1. Then ask them to try and login
1. After a few minutes, turn off password auth , restart sshd_config
1. Then explain this command `who | awk '{print $3}' | grep -v "pts/0" | xargs -r -n1 pkill -9 -t`
1. Then run the command and kick everyone off. They won't be able to get back in because I disabled passwords
1. Turn back on passwords, have everyone login, then go through the process again and kick, everyone off
1. Now that passwords are off, were all back at a terminal and cannot ssh. Now I will teach ssh keys.
1. Have everyone run ssh-keygen
1. Now you have a keypair, you can put the lock on a computer (pub key) and you can logon if you have the private key.
1. Note you cannot logon yet, because you didnt put your pub key on the machine!
1. Have all students look at their neighbors computer and make sure everyone has keys in the .ssh folder.
1. Now were going to move on to the next topic - users.
1. Linux supports multiple users. Take attendance and add a user for each student. Use a simple password for each.
1. Now change the root password to make sure no one can login as root. 
1. Now turn on passwords, but make sure no one logs in.
1. Now tell everyone to `ssh-copy-id` and put their keys on the machine.
1. When done, turn off password authentication and kick everyone. 
1. Now tell everyone to try to login. It should work without a password!!! And this is how ssh keys work!!
1. Now a question - the machine does not allow password authentication, but it does allow authentication with keys.
If you try to login with your home computer, will you be able to? [NO! You dont have the private key to unlock the machine! You only have the private key on this comptuer!]

1. now I install vim on the remote machine.
1. Now the class does vimtutor for 45 minutes.

After vim tutor, we will learn sftp
1. Show how sftp is like ssh, but you have local version of some commands and a remote version.
The sftp commands are not the bash commands you know, they are not zsh commands, they are not the programs in **/bin
1. Sftp can only do basic things like ls, cd, get put, and maybe a few others like mkdir and rm and cp and mv, 
1. Use vim to create some files on the droplet.
1. Use sftp to get the file from the droplet.
1. Create a file on your local machine and put it on the droplet.

