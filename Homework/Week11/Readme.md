# Week 11 Homework
This is a great homework assignment - you're going to master some essential Linux knowledge. If you scroll through the certification requirements here:

https://training.linuxfoundation.org/certification/linux-foundation-certified-sysadmin-lfcs/

you'll see under 'Storage Management' that to be able to:

* List, create, delete and modify physical storage partitions
* Configure systems to mount file systems at or during boot time
* Create and configure file systems

are listed as essential knowledge for linux professionals. In about 45 minutes of lecture today you've learned a great deal about these topics.


Your homework is to:
* create a droplet with a few users ( use adduser )
* add a disk to your droplet
* move /home to the new disk
* modify /etc/fstab such that your modifications survive a reboot

I want you to submit two images via pull request. 

The first image should contain the output of the following commands:
* uptime
* lsblk
* ls -l /home
* curl ipinfo.io/ip

and the second should be a screenshot of your digital ocean page showing the same ip address as the one shown in your curl command.

## Submission guidelines
Submit both images by pull request in the directory /Homework/Week11/StudentSubmissions/YourName by 4-16-2020 at 11:59 PM, no late homework please! This is important and youll need to understand these concepts so we can move on with further lecture topics.

