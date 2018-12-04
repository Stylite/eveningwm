/* This software is in the public domain
 * and is provided AS IS, with NO WARRANTY. */
#include <X11/Xlib.h>

/* defualt apps */
static const char term[] = "st &"; /* your terminal emulator */
static const char browser[] = "firefox &"; /* your browser */
static const char menu[] = "rofi -show run &"; /* your run function */
static const char bar[] = "polybar main &"; /*your bar */
static const char composer[] = "compton &"; /* your composer */

/* Keybinds */
static const char super = Mod4Mask;
static const char *movekeys[] = { "q", "e", "r" }; /* movement keys  */
static const char *programkeys[] = { "Return", "f", "d", "0" }; /* Program keys */

/* customization */
static const char wallpaper[] = "sudo wal -R";
static const int width = 100;
static const int height = 50;
