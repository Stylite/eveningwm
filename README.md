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
* Focus follows the mouse.
* Move a window with Alt + Left mouse button.
* Resize a window with Alt + Right mouse button.
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
make all
```

and to uninstall:
```
make clean
```

### Things still to be done/known bugs (no need to report these)
* Currently EveningWm doesn't know how to ignore bars, docks etc..
* If any modifier key in addition to Alt (e.g caps lock, num lock..) is pressed the keybinds won't work (I'm pretty sure I already know how to fix this tho)

### Gotta give credit where credit is due
* Nick Welch for creating TinyWm.
* [torvim](https://github.com/torvim) (browsing neutrawm's source code helped a ton.)
* The whole r/unixporn community for motivation.

### Warning
EveningWm is my first actual C project ever, so expect the worst and hope for the best.