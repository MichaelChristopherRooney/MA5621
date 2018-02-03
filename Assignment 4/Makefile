OBJECTS = ex01 ex02 ex01numbers.o ex02sqrt.o ex01numbers-test.o ex02sqrt-test.o
CC = gcc
CFLAGS = -Wall -lm

all: ex01numbers ex02sqrt

test: ex01numbers-test ex02sqrt-test

ex01numbers-test: ex01numbers
	./ex01 test

ex02sqrt-test: ex02sqrt
	./ex02 test

ex01numbers: ex01numbers.o ex01numbers-test.o
	$(CC) -o ex01 ex01numbers.o ex01numbers-test.o $(CFLAGS)

ex01numbers.o: ex01numbers.c ex01numbers-test.c
	$(CC) -c ex01numbers.c ex01numbers-test.c $(CFLAGS)

ex01numbers-test.o: ex01numbers.c ex01numbers-test.c
	$(CC) -c ex01numbers-test.c ex01numbers.c $(CFLAGS)

ex02sqrt: ex02sqrt.o ex02sqrt-test.o
	$(CC) -o ex02 ex02sqrt.o ex02sqrt-test.o $(CFLAGS)

ex02sqrt.o: ex02sqrt.c ex02sqrt-test.c
	$(CC) -c ex02sqrt.c ex02sqrt-test.c $(CFLAGS)

ex02sqrt-test.o: ex02sqrt-test.c ex02sqrt.c
	$(CC) -c ex02sqrt-test.c ex02sqrt.c $(CFLAGS)

clean:
	rm -f $(OBJECTS) $(EXEC_NAME)

