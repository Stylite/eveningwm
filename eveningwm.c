/* This software is in the public domain
 * and is provided AS IS, with NO WARRANTY. */

#include <X11/Xlib.h>
#include <stdlib.h>
#include "config.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
    system(bar);
    system(composer);
    Display * dpy;
    XWindowAttributes attr;
    XButtonEvent start;
    XEvent ev; 
    Window foc;
    int revert_to;
    /*char term[] = "st &";
    char brow[] = "firefox &";
    char menu[] = "rofi -show run &"; */

    /*If we can't open display return 1*/    
    if(!(dpy = XOpenDisplay(0x0))) return 1; 
	
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym(movekeys[0])), super,
        DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym(movekeys[1])), super,
        DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym(movekeys[2])), super,
        DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym(programkeys[3])), super,
        DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym(programkeys[0])), super,
        DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym(programkeys[1])), super,
        DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);

    XGrabButton(dpy, 1, super, DefaultRootWindow(dpy), True,
        ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);
    XGrabButton(dpy, 3, super, DefaultRootWindow(dpy), True,
        ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);
    
    start.subwindow = None; 
    for(;;)
    {
        XNextEvent(dpy, &ev);
	    XGetInputFocus(dpy, &foc, &revert_to);
	
	if(ev.type == KeyPress && ev.xbutton.subwindow != None)
	{ 
	    if(ev.xkey.keycode == XKeysymToKeycode(dpy, XStringToKeysym(movekeys[0])))
	        XDestroyWindow(dpy, foc);	
    	else if (ev.xkey.keycode == XKeysymToKeycode(dpy, XStringToKeysym(movekeys[1])))
  	        XLowerWindow(dpy, foc);
	    else if (ev.xkey.keycode == XKeysymToKeycode(dpy, XStringToKeysym(movekeys[2])))
		    XRaiseWindow(dpy, foc);
	}

	if(ev.type == KeyPress)
	{
	    if(ev.xkey.keycode == XKeysymToKeycode(dpy, XStringToKeysym(programkeys[0])))
		    system(term);
	    else if(ev.xkey.keycode == XKeysymToKeycode(dpy, XStringToKeysym(programkeys[1])))
		    system(browser);
	    else if(ev.xkey.keycode == XKeysymToKeycode(dpy, XStringToKeysym(programkeys[2])))
		    system(menu);
	    else if(ev.xkey.keycode == XKeysymToKeycode(dpy, XStringToKeysym(programkeys[3])))
	  	    XCloseDisplay(dpy);
	}

	if(ev.type == ButtonPress && ev.xbutton.subwindow != None) 
    	{
	    /*Save the windows size and location before doing anything*/ 
	    XGetWindowAttributes(dpy, ev.xbutton.subwindow, &attr);
	    XSetInputFocus(dpy, ev.xbutton.subwindow, RevertToParent, CurrentTime); 
	    start = ev.xbutton;  
    	}
    	else if(ev.type == MotionNotify && start.subwindow != None)
    	{
            int xdiff = ev.xbutton.x_root - start.x_root;
            int ydiff = ev.xbutton.y_root - start.y_root;
            XMoveResizeWindow(dpy, start.subwindow,
                attr.x + (start.button==1 ? xdiff : 0),
                attr.y + (start.button==1 ? ydiff : 0),
		        /*Minimum window size when resizing is 100x50 pixels because
		         *I don't think there is any need for smaller windows*/
                MAX(width, attr.width + (start.button==3 ? xdiff : 0)),
                MAX(height, attr.height + (start.button==3 ? ydiff : 0)));
    	}
        else if(ev.type == ButtonRelease)
            start.subwindow = None;
   }
}
