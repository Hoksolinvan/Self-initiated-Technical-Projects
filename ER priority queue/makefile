
CC=gcc

# The line with -DDEBUG can be used for development. When
# building your code for evaluation, however, the line *without*
# the -DDEBUG will be used.
#

CFLAGS=-c -Wall -g -DDEBUG -D_GNU_SOURCE -std=c99 -O0


all: pq-tester

pq-tester: pq-tester.o list.o emalloc.o
	$(CC) pq-tester.o list.o emalloc.o -o pq-tester

pq-tester.o: pq-tester.c list.h emalloc.h
	$(CC) $(CFLAGS) pq-tester.c

list.o: list.c list.h emalloc.h
	$(CC) $(CFLAGS) list.c

emalloc.o: emalloc.c emalloc.h
	$(CC) $(CFLAGS) emalloc.c

clean:
	rm -rf *.o tester 
