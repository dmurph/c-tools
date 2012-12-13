all: test

CC = clang 

checks.o: checks.c checks.h

log.o: log.c log.h

test.o: test.c checks.h log.h

test: test.o checks.o log.o
	$(CC) test.o checks.o log.o -o test

clean:
	rm -f *.o test