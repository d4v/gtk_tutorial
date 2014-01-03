CC=gcc

CPPFLAGS=`pkg-config --cflags gtk+-x11-3.0 gmodule-2.0`

CFLAGS=-g -Wall

LDLIBS=`pkg-config --libs gtk+-x11-3.0 gmodule-2.0`

main:


.PHONY: clean
clean:
	rm -f *.o main
