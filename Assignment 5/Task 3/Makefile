OBJECTS = my_grep.o
EXEC_NAME = my_grep
CC = gcc
CFLAGS = -Wall -lm

all: my_grep.o
	$(CC) -o $(EXEC_NAME) my_grep.o $(CFLAGS)

test: all
	chmod +x test.sh
	./test.sh

my_grep.o: my_grep.c
	$(CC) -c my_grep.c $(CFLAGS)

clean:
	rm -f $(OBJECTS) $(EXEC_NAME)

