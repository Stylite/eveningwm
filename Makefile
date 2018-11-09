PREFIX?=/usr/X11R6
CFLAGS?=-Os -pedantic -Wall

all:
	$(CC) $(CFLAGS) -I$(PREFIX)/include eveningwm.c -L$(PREFIX)/lib -lX11 -o eveningwm

install:
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f eveningwm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/eveningwm

clean:
	rm -f ${DESTDIR}${PREFIX}/bin/eveningwm eveningwm

