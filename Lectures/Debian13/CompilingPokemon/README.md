# Compiling Pokemon Yellow

## Introduction
In this activity we will set up a Linux server with a toolchain for compiling gameboy games

Then we'll download the source code for Pokemon Yellow.

Then we'll compile the game and run the ROM on an emulator.

Isn't it amazing what you can do on Linux?!


## Download the Code

The source code for Pokemon Yellow is on github
https://github.com/pret/pokeyellow

Isn't that amazing!?!?!

Follow the install instructions to set up your computer. Scroll down to the section about Debian / Ubuntu.

They recommend to download and build rgbds 1.0.1 FROM SOURCE. 
https://github.com/pret/pokeyellow/blob/master/INSTALL.md

After you've setup your rgbds toolchain, then scroll down to the section "Build Pokeyellow"

## Verify your ROM is correct
After you've built the ROM it should have created a file called pokeyellow.gb or pokeyellow.gbc or pokeyellow.gba *sry cant remember which one*

You can verify the sha1 hash of the ROM. It should match the hash shown in the README here:
https://github.com/pret/pokeyellow/tree/master

## Run it!

A very hard working undergrad at the University of Las Vegas made a website that runs a really great GameBoy Advance Emulator.

Check it out!
https://gba.nicholas-vancise.dev/

Click the upload files button and upload your ROM. ( NOTE You'll need to use sftp first to get your ROM from your droplet back to your PC).

## Hacking
Now you have a copy of pokemon yellow! You can install an emulator on your phone and play the game now if you want!

Want to hack the game though? Let's start with something simple. 

In this game Pikachu follows you around. Let's change the ROM so that the pokemon that follows you isn't pikachu, but is some monster.

Use `cp` to copy the `monster.png` file in `pokeyellow/gfx/sprites` to `pikachu/png`

In other words, do this on your droplet:

```
cd ~/pokeyellow/gfx/sprites
cp monster.png pikachu.png
cd ~/pokeyellow
make
```

This will replace the pikachu sprite with the  monster sprite, then recompile the game.

Now when you play the game, it's not Pikachu that follows you, but a different pokemon!!!

## Running your own emulator
The code for that awesome emulator website is online
https://github.com/thenick775/gbajs3

But that's hard to setup.

You could run mgba on a bunch of platforms.
https://mgba.io/downloads.html

If you want to install mgba on your debian or ubuntu laptop, you could 

`apt install mgba-qt`

You could install batocera linux on an old pc in your house too
https://batocera.org/
I use batocera for my emulator pc at home - its a linux that comes bundled with all kinds of old playstation, nintendo and sega emulators.


or you could get an emulator on your phone.

## More hacking
The rest is on you! 
You can pick up a cool book like this one :
https://nostarch.com/game-boy-coding-adventure

Or find a bunch of great references online:
https://gbdev.io/gb-asm-tutorial/

Google is your friend. There are so many great references about how gameboy works. 

I love gameboy advance because its a beautiful looking console, it's offline, and you can program it for free. 

Today to program for PC or Switch or PS5 is complex. Gameboy is complex too but the games are offline, you don't need a subscription, etc..

It's a cool platform.

## Alot of ppl are interested in gameboy
checkout analogue pocket, it's a cool FPGA based gameboy emulator.
and checkout Palmer Luckey's gameboys too ( he's the guy who invented Oculus, and now he runs a big military defense contractor company called anduril).