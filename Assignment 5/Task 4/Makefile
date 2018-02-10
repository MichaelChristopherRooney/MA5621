OBJECTS = my_hexdump.o
EXEC_NAME = my_hexdump
CC = gcc
CFLAGS = -Wall -lm

all: my_hexdump.o
	$(CC) -o $(EXEC_NAME) my_hexdump.o $(CFLAGS)

my_hexdump.o: my_hexdump.c
	$(CC) -c my_hexdump.c $(CFLAGS)

clean:
	rm -f $(OBJECTS) $(EXEC_NAME)

