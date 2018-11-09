/* This software is in the public domain
 * and is provided AS IS, with NO WARRANTY. */

#include <X11/Xlib.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
    Display * dpy;
    XWindowAttributes attr;
    XButtonEvent start;
    XEvent ev; 
    char term[] = "urxvt &";

    /*If we can't open display return 1*/    
    if(!(dpy = XOpenDisplay(0x0))) return 1; 
	
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("q")), Mod1Mask,
            DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("d")), Mod1Mask,
            DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("r")), Mod1Mask,
            DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("0")), Mod1Mask,
            DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("Return")), Mod1Mask,
         DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);

    XGrabButton(dpy, 1, Mod1Mask, DefaultRootWindow(dpy), True,
            ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);
    XGrabButton(dpy, 3, Mod1Mask, DefaultRootWindow(dpy), True,
            ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);

    start.subwindow = None;
   
    for(;;)
    {
        XNextEvent(dpy, &ev);
	/*Use xev to get keycodes if you want to modify these*/
	switch(ev.xkey.keycode)
	{
		case 36:	
			system(term);
		case 19:
			XCloseDisplay(dpy);
		case 24:
			XDestroyWindow(dpy, ev.xbutton.subwindow);	
		case 40:
			XLowerWindow(dpy, ev.xbutton.subwindow);
		case 27:
			XRaiseWindow(dpy, ev.xbutton.subwindow);
	}

        if(ev.type == ButtonPress && ev.xbutton.subwindow != None)
        {
	    /*Save the windows size and location before doing anything*/
            XGetWindowAttributes(dpy, ev.xbutton.subwindow, &attr);
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
                MAX(100, attr.width + (start.button==3 ? xdiff : 0)),
                MAX(50, attr.height + (start.button==3 ? ydiff : 0)));
        }
        else if(ev.type == ButtonRelease)
            start.subwindow = None;
    }
}
