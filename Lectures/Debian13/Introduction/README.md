# Welcome to the Class!
Usually about 14weeks per semester
week 1 - introduction. 
Absolute vs. relative paths 
week 2
b) command line usage: cd, ls, rm, mkdir, cp, cp -r, cp -a, rm -r, rm -rf. Understand absolute vs relative paths. Ssh with passwords. Important environment variables. The HOME directory. root of file system vs root user. Home directory vs root directory vs root of file system.
a) Explain ssh and sftp and how they work with keys. 

elephant in the room: free credit. Ive been using my link for a long time. Im not sure who used the link ad who didnt. #1 please carefully read instructions for what I want you to do. I think you did, just as a general thing, sometimes people dont, so always read instructions carefully, dont ask chatgpt and dont reinvent things.
#2 you can reach out to digital ocean customer service and explain the issue to them. In my experience its a great company with great customer service, they should get you sorted out. #3 this class has no textbook, so even if you dont get the free credit, this class will still be only a couple of dollars. Thats way way way cheaper than a textbook. Turn your droplet on and turn it off.

Im proud to be here teaching this class. I studied so much and work so hard at my career and I really like it. This class is about you so I want you to shine in this class, and I want you to know everything I know and more. That's why we're here, the student is supposed to outshine the professor. You all are cs / cyber sec majors and this is an amazing major to have. Work hard. There is a magic formula for becoming a better programmer/hacker/security analyst... sit at your computer and do stuff. When you're tired, get up, get some exercise, have a coffee if you want, and go sit some more and continue coding. There's so much to know. Every day I learn, every day the pros are learning. NJCU is just a tiny part of your technical life, you just spend a llittle time here, do some assignments, get a good grade, and then go out in the real world.

Career advice. Can I give some? Show of hands
1. Do cool projects. If you can, put it on the internet. Record a little yt vid, make a blog, whatever. Publicize your skills. 
1. Too many people gradduating out of here who can't write a for loop, never made a website, never made a video game, dont know about encryption algorithms. Youre a cybersec major - so I ask you to tell me about sha1 vs sha256 hash and you can't? That's not great.
1. Careful with your friends. I had friends who used to hold me back these guys were smoking alot of weed, alot of cocaine users, party guys, going to the club and buying 200 bottles of tequila. These guys are still doing okay in life by and large, but for me I'm glad I stayed on the book path, I dont think I would have had the moderate success I've had if I didn't study. Partying is good, but you gotta know theres a time to party and a time to be professional.
1. Talk to people. Go to tech conferences was big for me. They have tutorials and there are often big super nerds there 
1. Go to grad school if its cheap. A bachelor in CS should set you up for a six figure salary if youre a decent programmer with a portfolio. But learning is always good. a master or phd is good if it makes sense for you. But you can def make 70 or 120k a year if youre a great programmer, no need for a master.
1. Letters of recommendation are everything. If you can do research projects, do good in your classes and be friendly with your teachers, that's great. Life is easier if you have people behind you.
1. Just some thoughts that's all. Work hard, build relationships, be all that you can be. 

- hidden files / directories start with .
- create an ssh key using ssh-keygen. This key lasts forever, don't lose it. Optional password.
- anyone who has the private key can hack you. This is a secret! 
- you can give the public key to everyone in the whole world. It's public
- the key needs to be in a folder ~/.ssh on windows/mac/linux laptop so you can connect to your droplet
- ssh keys are used for other things besides droplets. Remember this class is about linux/unix, but also about being a great introduction to advanced computer topics in general. ssh is part of that.
- show how ssh keys are used on github. We'll talk about github later in the semester.
- you can put that private ssh key on a usb stick and bring it to all your computers. Do whatever you want with it, but don't lose it!!!

-  class activity: add a classmates ssh key to your droplet. use ssh-copy-id to copy it onto the droplet.
Activity 1
1. create a droplet with password
2. create an ssh key if you don't have one already
3. use ssh-copy-id to get your key onto the droplet
4. tell your classmate to use ssh-copy-id to copy his/her key to the droplet. Now you should both be able to get in without a password.

Activity 2
1. create a droplet with ssh key
1. tell your classmate to try to copy the key in 

other info
ssh uses port 22
ssh is very configurable
have a look at the config files in /etc
note there is ssh and sshd
sshd is the server program, ssh is the client program, both are highly configurable
show the great book about ssh.
show the students that password login is off on that droplet

Week 3
a) review week 1. Basic vim.
class idea:
first show normal mode, insert, command mode
b) learn more commands. head, tail, top, cat, more, less. Mention ctrlc/ctrlz. Always happens with cat that a student get stuck. Make files with vim.
Week 4
a) stdin, stdout, stderr
b) bash scripting
Week 5
a) sed, grep, pipes. More vim.
b) More vim, more command line tools.
Week 6
a) awk
b) find and pipes
Week 7
a) Bash scripting, loops, arrays
b) Look at a few examples from the wicked cool shell scripting book.
Week 8
a) more bash scripting
b) more bash scripting
Week 9
a) regular expressions in sed and grep
b) regular expressions in awk
Week 10
a) Processes, signals. top, htop, kill, pkill, ctrl c, ctrl z

b) bash scripts and signals
Week 11
a) Static website
b) Python
Week 12
a) Users, groups, permissions
b) Users, groups, permissions
Week 13
a) git and github
b) group coding assignment with github
Week 14
a) gitlab server
b) docker

 
CONSIDER LEAVING THIS AS A SEPARATE CLASS
Week 13
a) sqlite murder mystery
b) postgres database setup
CONSIDER LEAVING THIS AS A SEPARATE CLASS FOR ANOTHER SEMESTER.
Week 13
a) DYNAMIC WEBSITE
b)
Week 14
a) DOCKER, DOMAIN NAME, LETS ENCRYPT, NGINX
b)


