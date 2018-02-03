OBJECTS = my_seq.o
EXEC_NAME = my_seq
CC = gcc
CFLAGS = -Wall -lm

all: my_seq.o
	$(CC) -o $(EXEC_NAME) my_seq.o $(CFLAGS)

my_seq.o: my_seq.c
	$(CC) -c my_seq.c $(CFLAGS)

clean:
	rm -f $(OBJECTS) $(EXEC_NAME)

