CC=/usr/bin/cc
CFLAGS=-c -Wall -Wextra
AR=/usr/bin/ar
ARFLAGS=-rv

cqueue.a: cqueue.o
	$(AR) $(ARFLAGS) cqueue.a $<

cqueue.o: cqueue.c
	$(CC) $< $(CFLAGS)
