CC=gcc

CPPFLAGS=`pkg-config --cflags gtk+-x11-3.0`

LDLIBS=`pkg-config --libs gtk+-x11-3.0`

main:


.PHONY: clean
clean:
	rm -f *.o main