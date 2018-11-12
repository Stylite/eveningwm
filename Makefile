PREFIX?=/usr/X11R6
CFLAGS?=-Os -pedantic -Wall

all:
	$(CC) $(CFLAGS) -I$(PREFIX)/include eveningwm.c -L$(PREFIX)/lib -lX11 -o eveningwm

clean:
	rm -f  eveningwm

