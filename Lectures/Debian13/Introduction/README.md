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
1. Do cool projects. If you can, put it on the i nternet. Record a little yt vid, make a blog, whatever. Publicize your skills. 
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
vim is available on all platforms. It's the best text editor!
it's so good, other tools are copying it look, android studio:
https://medium.com/@ahmedrizwan/vim-ing-on-android-studio-acb8f8078101
and vs code
:https://marketplace.visualstudio.com/items?itemName=vscodevim.vim
first show normal mode, insert, command mode.

lets write a program my_first_script.sh
echo "hello world!"
save it and run it like bash my_first_script.sh

let's do anther one my_second_script.sh
mkdir -p A/B/C
touch A/B/C/myFile.txt
save it and run it

Have class write a poem, poem.txt
roses are red
violets are blue
sugar is sweet
and so are you

and finally let's bring it all together with what we know about vim and the command line
write four files
line1.txt: roses are red
line2.txt: violets are blue
line3.txt: sugar is sweet
line4.txt: and so are you

then run this command: cat line1.txt line2.txt line3.txt line4.txt
this will concatenate the files!

look at ssh handout

then run this command: cat line1.txt line2.txt line3.txt line4.txt
this will concatenate the files!

hjkl move around (don't use the arrows, and forget about the mouse.)


b) Looking at files on the command line.
 head, tail, cat, more, less. 
	 show head command to look at the top few lines of a file
	 head/tail commands to look at a few lines in the middle of a file.
	 
	head -n 10
	tail -n 20
	BONUS syntax with tail
	tail -n +10 = start at line ten and print the rest

	Exercise:
	Create a file "numbers.txt"
	one
	two
	...
	twenty

	and use head and tail to get lines 5-10

	head -n10 | tail -n6

	or 
	tail -n +5 | head -n6

	 Mention ctrlc/ctrlz. Always happens with cat that a student get stuck. 
	 look at these three examples:
	 cat
	 head
	 tail
	 all three of these will hang. To get out, ctrl + C. If that doesnt work, ctrl + z.
	 A mnemonic that I invented - I dont think anyone else has this:
	 <WAIT> for the non english speakers - which letter can sound like k in kill?
	 	C or Z?

	 	OK then , which letter can sounds like s in stop? z or c?
	 	ACTUALLY BOTH!!! How crazy... any English word where c sounds like s?

	 	ANYWAY heres the mnemonic I used to use before I internalized the distinction:
	 c is like k, like kill
	 z is like s, like stop

	TEAM WORK:
	Every student log into my droplet and make a file with 10 numbers. Put your file in the directory /root/number_words
	one-ten
	eleven-twenty

	and name your files numbers001.txt, numbers002.txt, etc.

	Then I'll use cat to glue them together. 


	do it again, but this time in /root/numbers
	and create a file with 10 random numbers like
	1
	3
	4
	19
	23
	1274
	1

	then I will cat the files together and search for the min
	cat * | sort -g | head -n1
	and to find the max
	cat * | sort -gr | head -n1


VIM is also useful for looking at files. VIM is really amazing... If you go on a job interview and you have to do a programming task, or a system admin task like modifying the ssh configuration on a machin.... and you fire up vim to solve the problem - you're hired! If they see that you are a vim wizard, they will assume that you're some kind of genius. Don't brag about it, just open vim and solve the problem quietly and humbly and you will look like a real wizard.


e) o and shift O to enter insert mode
hjkl move around (don't use the arrows, and forget about the mouse.)

work through vim adventures  https://vim-adventures.com/

prize for anyone who finishes it?

Week 4
a) stdin, stdout, stderr, pipes.

Tell what is stdin, stdout, stderr.

> ,>>, 1>, 2>, 1>>, 2>>, 1>/dev/null 2>&1

look at wc -l , wc, wc -c, wc -w

cut -d
I rarely use stdin explicity like this:

wc 0< cpp_example_01.cpp

you COULD do that, and many commands will read stdin, but usually I use stdin for piping. 

grep "thing" FILES

if you want to grep recursively through everything in your current directory and the subdirectories, you would
grep -r "thing" .

lets use by absolute and relative path.

grep for a config file that allows editing a port
grep -r "Port" /etc

Look through this:
https://github.com/melvyniandrag/LinuxClassRepo/blob/master/Lectures/2021Version/Week02_Pipes_IORedirection_and_More_Command_Line_Tools/Lecture.pdf

Talk about games:
There are many awesome command line games.
For example, this one: 
https://github.com/veltman/clmystery

  410  cat AAA Delta_SkyMiles Terminal_City_Library Museum_of_Bash_History  | sort | uniq -c | awk '$1==4 { print $2, $3}'

Look at the programs here:
 ~/Desktop/stdinStdoutStderrFileDescriptors

Show grep | sort | uniq -c in C... write code to implement this without |

b) grep, uniq -c, and the pipe command below. Then, clmystery
grep

cat names
Don
Donald
don
Donnie
Don
Udon

grep -i don names | sort | uniq -c

also see grep -w and grep -wi


find_max

# shuf
25 is the num of random numbers generated

shuf -i 0-999 -n 25

# paste
see man paste
paste "merges lines of files". If the file is "-", it pulls from stdin.

so you could make 5 files of numbers and then merge them like
paste -d, file1 file2 file3 file4 file5

shuf -i 0-999 -n 25 | paste -d, - - - - -

shuf -i 0-999 -n 250 | paste -d, - - - - - | tee numbers.csv | cut -d"," -f2 | sort -g | head -n1

Week 5
---------------------
Only 1 class this week!
Let's do the following:
1. Discuss the exam
2. Discuss the clmystery
3. Deploy a jellyfin server. You'll be shocked at how straightforward this is, now that you have a good basic knowledge of using the command line.


Week 5
a) sed, grep, awk, regular expressions
Exercise 1: Use sed to replace all strings matching a certain pattern. The output file should have the expected md5sum.
Exercise 2: Use grep to find all lines matching certain criteria.
Use >  and >> to dump all the matches into a file matches.txt
Sort the lines in the file and put them in a file called sorted.txt
The md5sum of the file should be X
Exercise 3: Find all lines that match a certain format and reformat the lines.
e.g. find all people who earned more than $100000 per year and print a file like "jon earned 500000 per year"

b) Intro to Bash scripting. find, xargs, xargs with sh -c.

Week X
----------
Each week take a few students and work on a game server project.
Let the other students work on a few handouts.
- website
- python
- c
- git



Week 6
a) Bash scripting, loops, arrays
b) Example from bash scripting book

Week 6
a) c programming intro. pipe, fork, exec, stdin, stdout.
b) building a program from source: awk.

Week 7 - git is great to do while I'm away.
a) git. Use git a bunch and then  turn off machine. Oh no! We lost our work!
b) Do it again, but this time set up a github account and push

Week 8 -Exam
Do the exam while I'm away? Static website.

Week 9
a) Example from bash scripting book
b)  awk

Week 10
a) Processes, signals. top, htop, kill, pkill, ctrl c, ctrl z
b) bash scripts and signals

Week 11
a) Users, groups, permissions. chmod + chown
b) project that brings everything together.

Week 12
a) over the wire
b) over the wire

Week 13
a) Make our own over the wire
b) Make our own over the wire

Week 14
a) review
b) review

Bonus topics
programming in C
programming in rust
programming in Python
postgres database configuration
dynamic website



Exam 1:
MAKE A STATIC WEBSITE. DEPLOY WITH APACHE.
Put your resume on the website.

Exam 2: 
MAKE A STATIC WEBSITE.
Enhance your website. Add a button to download your resume.
Use a latex template to render it nicely as a pdf.

Exam 3:
Bundle your static website with a docker file.

Exam 1 could be this?
Before teaching git, consider cloning these things to your machine:
such as this:
https://github.com/veltman/clmystery
-- then use the code... then a few weeks later talk about what git is.


https://github.com/bloomberg/git-adventure-game

https://github.com/lxgr-linux/pokete

Setting Up a Multi-User Chatroom (Ncat Broker Mode)

    Server/Host Setup: Run this command on a machine to start the chat broker:
    ncat --broker --listen -p 1234
        This opens port 1234 and allows multiple users to join.
    Client/User Connection: Other users can connect using the IP address of the server machine:
    ncat <Server_IP> 1234 

Key Features

    Broadcasting: Any message sent by one user is seen by everyone else.
    Ncat Benefits: Unlike traditional Netcat, Ncat (part of the Nmap package) supports SSL/TLS encryption for secure chat.
    Simple Interface: Provides a straightforward command-line chat experience. 

For large numbers of people, ensuring the server has enough bandwidth is crucial for performance.


Bonus content:
 
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


