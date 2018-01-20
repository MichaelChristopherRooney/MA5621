OBJECTS = prog ex01numbers.o
CC = gcc
CFLAGS = -Wall -lm -g
EXEC_NAME = prog

all: ex01numbers.o
	$(CC) -o $(EXEC_NAME) ex01numbers.o $(CFLAGS)

ex01numbers.o: ex01numbers.c
	$(CC) -c ex01numbers.c $(CFLAGS)

clean:
	rm -f $(OBJECTS) $(EXEC_NAME)

