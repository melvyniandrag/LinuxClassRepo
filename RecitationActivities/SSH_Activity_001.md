# SSH Activity
This activity will strengthen your knowledge of ssh.

## sftp
You can use sftp to upload and download files from your server
```
sftp root@ipaddress # login
lls # list files on your local machine
lcd # change directory on your local machine
lpwd # get your local pwd
ls # list files on the remote
cd # change dir on the remote
pwd # list pwd on the remote
put file.txt # will upload a file from your local machine
get file.txt # will get a file from the remote to your lpwd.
```

## ssh
ssh uses key pairs and allows you to securely login to remote servers. If you put you .pub key in the `.ssh/authorized_keys` file on the remote,
then have the private key in the `.ssh` directory of your local machine, you will be able to login. Simple as that!

There are actually more concerns about permissions, but we'll discuss that in the future or as necessary. 

Use analagy of combo locks and password. You can have 10 locks with the same password. Only you know teh password. You can lock all your stuff with those locks, and you can get into any one with the same password.

The password is your private key. Only you know it. The locks are your public key. 

you can put these locks on all your droplets. And you can get into any droplet you own, because you have the passcode.

No one else knows the passcode though! No one else has the private key!

# Activity
Get a partner
Both create a droplet.
Exchange public keys.
Use sftp to upload your partner's ssh key to your droplet. 
Your partner should now be able to log in to your droplet!

# Activity 2
Simple ssh config
You can have multiple ssh keys!

Create a second ssh key on your local machine.

Create a file ~/.ssh/config on your local machine

File contents should be like
```
# Personal account
Host myDroplet
    HostName ip.of.your.droplet
    User root
    IdentityFile ~/.ssh/id_rsa 
    IdentitiesOnly yes

# Work account
Host partnersDroplet
    HostName ip.of.your.partner
    User root
    IdentityFile ~/.ssh/id_ed25519
    IdentitiesOnly yes
```

Now you can get into myDroplet if you put id_rsa.pub on it.
You can get into partnersdroplet if you put id_ed25519 on it.

And its even easier!

No need to specify user name!

```
ssh partnersDroplet # just works!
ssh myDroplet # jsut works!
```

Mainly I use this for managing access to my personal and professional accounts.
I dont want to give my personal key to my company. And I dont want my professional keys in my personal stuff.
