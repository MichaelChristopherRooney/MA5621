OBJECTS = round.o
EXEC_NAME = round
CC = gcc
CFLAGS = -Wall -lm

all: round.o
	$(CC) -o $(EXEC_NAME) round.o $(CFLAGS)

round.o: round.c
	$(CC) -c round.c $(CFLAGS)

clean:
	rm -f $(OBJECTS) $(EXEC_NAME)

