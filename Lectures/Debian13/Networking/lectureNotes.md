# networking
## Set up server
1. Create droplet called networking (or server)
1. apt install apache2 ncat

## Set up client
2. Create a droplet called client
1. apt install ncat curl
> netcat is the oldschool 90s tool
> ncat is maintained by the nmap group and its a modern implementation, supposed to much better.
> I dont know much about these tools, I use them for just quick network tests, but you cyber sec ppl should know about
> these tools. You should maybe find a class about nmap. ncat, netstat, and other networking tools. 
> ncat/netcat is called the "swiss army knife" of networking
> curl is another powerfull networking tool. I also dont know all the details of it - I use it for quick network tests
> with my http / https servers. You cyber sec or sysadmin people will probably find a bunch of uses for this tool.

## curl
from your client run

```
curl server_ip
```

and you'll see the apache2 default info in your browser

by default curl uses port 80. You could also type

```
curl server_ip:80
```

You can also go back on your server and change the index.html page to something like

```
<h1>hello</h1>
<p> is curl working></p>
```

And if you want to see the full http message from the server

```
curl -v server_ip
```

And you can do the http request with ncat too if you want

```
printf "GET / HTTP/1.1\r\nHost: anything\r\nConnection: close\r\n\r\n" | ncat 137.184.66.239 80
```

ncat gives you very lowlevel control of what you want to send. This looks really gnarly. Also note that we used printf and not echo to print our string out through the pipe... printf is like echo but gives you more power over what you print.

We haven't talked about http/https in this class in detail yet. It's a protocol, there is lots of stuff that needs to happen. That's why you use tools like apache2 to run your site, and thats why you use curl or a browser to access the website!! Webservers like apache and nginx handle the complicated http/https stuff for you on the server, and curl/browsers handle the complicated stuff on the client side!!!

## ncat
Now lets talk more about ncat
As you saw you can use ncat to talk to your webserver  - ncat is a powerful tool for sending and receiving raw data over networks
you have total control over the data you send, to where you send it, and you can see the full messaging. This is super useful if you're doing cyber security or learning about protcols.

Heck, try this!

```
ncat server_ip 22
```

you'll see you're talking right to the ssh daemon on your server. Hit enter a couple of times and youll see error messages. ssh is complicated. To talk to ssh you'll probably use a program like `ssh` instead of writing raw bytes over ncat! But thats cool, isn't it!!

Also, as you walked into class today you saw that I was using ncat to run a listener - a server - on port 5000 of my server, and the arduino was talking to it.

Now let's do a fun little experiment with ncat to make a chat room! Do this with your partner

## ncat demo
1. show a class demo. Show how my 2 clients can chat over the server to each other using a script.
### On server
Run this to set up the server as our chatroom host
```
ncat -kl 5000 --chat
```

### on clients 
```
ncat server_ip 5000
```

and then start chatting!!

But note this kind of stinks. 
1. There is no user name displayed for the people talking
1. There is some spam at the beginning of the line about the user whos writing, this is a username that comes from the server. 

Lets make this better

Run this script on the client:

```
GET THE CODE FROM chat_client.sh that's in this directory
```

