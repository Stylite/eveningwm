# EveningWm

## This is a fork of https://gitlab.com/mrmessyhair/eveningwm/tree/master

Less features, less problems

![](https://preview.redd.it/zy0hoxsicvx11.png?width=960&crop=smart&auto=webp&s=0fd9ce892e57e8a8631af4543e48f4b6e42558b3)

### What is EveningWm and why would I ever use it?
EveningWm is a super minimal floating X window manager built using Xlib. It is currently only 95 SLOC (generated by sloccount) and it features a configuration file.
With more features, comes more bugs and that's what EveningWm is trying to solve. In the best case scenario, you'll forget that your running a wm at all ;)


This project is a proud fork of the most smallest wm, [TinyWm](http://incise.org/tinywm.html)
(originally written by Nick Welch <nick@incise.org> in 2005 & 2011.)

### Default keybinds
* Sloppy focus follows the mouse, to properly focus a window press Alt + Mouse1 on it.
* Move a window with Alt + Mouse1
* Resize a window with Alt + Mouse3
* Raise a window with Alt + r
* Lower a window with Alt + d
* Launch a terminal with Alt + Return (default is urxvt)
* Launch a browser with Alt + f (default is firefox)
* Close EveningWm with Alt + 0

### Configuration
EveningWm is configured by editing the config.h file.
Defualt settings are there but it's highly recommened you configure it to how you like

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

### Things still to be done/known bugs (send help)
* Currently EveningWm doesn't know how to ignore bars, docks etc..
* If any modifier key in addition to Alt (e.g caps lock, num lock..) is pressed the keybinds won't work.
* ~~For some reason firefox context menus stopped working even thought I'm 100% sure they worked just a couple of days ago :(~~

### Gotta give credit where credit is due
* Nick Welch for creating TinyWm.
* [torvim](https://github.com/torvim) (browsing neutrawm's source code helped a ton.)
* The whole r/unixporn community for motivation.

### Warning
EveningWm is my first actual C project ever, so expect the worst but hope for the best.
