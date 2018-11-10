# EveningWm

Manage your windows while sipping on some evening tea ;)
![](scrot.png)

### What is EveningWm?
EveningWm is a minimal floating window manager built
using Xlib.

This project is a proud fork of the most smallest wm, [TinyWm](http://incise.org/tinywm.html)
(originally written by Nick Welch <nick@incise.org> in 2005 & 2011.)

EveningWm isn't trying to be the next i3 replacement, this was just a small evening project of mine (hence the name.)

### Features
* Sloppy focus follows the mouse, to properly focus a window press Alt + Mouse1 on it.
* Move a window with Alt + Mouse1
* Resize a window with Alt + Mouse3
* Raise a window with Alt + r
* Lower a window with Alt + d
* Launch a terminal with Alt + Return (default terminal is urxvt)
* Close EveningWm with Alt + 0

### Configuration
EveningWm is configured by editing the "massive" source code.

### Build requirements
* gcc
* make
* Xlib headers

### Installation
To install EveningWm run:
```
sudo make all install
```

and to uninstall:
```
sudo make clean
```

### Things still to be done/known bugs (send help)
* Currently EveningWm doesn't know how to ignore bars, docks etc..
* If any modifier key in addition to Alt (e.g caps lock, num lock..) is pressed the keybinds won't work.
* ~~For some reason firefox context menus stopped working even thought I'm 100% sure they worked just a couple of days ago :(~~

### Gotta give credit where credit is due
* Nick Welch for creating TinyWm.
* [torvim](https://github.com/torvim) (browsing neutrawm's source code helped a ton.)
* The whole r/unixporn community for motivation.

### Warning
EveningWm is my first actual C project ever, so expect the worst and hope for the best.
I've also never written a Makefile before so please report if I did something stupid.