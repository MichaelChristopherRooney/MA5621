OBJECTS = round.o
EXEC_NAME = round
CC = gcc
CFLAGS = -Wall -lm

all: round.o
	$(CC) -o $(EXEC_NAME) round.o $(CFLAGS)

test: all
	chmod +x test.sh
	./test.sh

round.o: round.c
	$(CC) -c round.c $(CFLAGS)

clean:
	rm -f $(OBJECTS) $(EXEC_NAME)

