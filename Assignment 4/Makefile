OBJECTS = ex01 ex02 ex01numbers.o ex02sqrt.o
CC = gcc
CFLAGS = -Wall

all: ex01numbers ex02sqrt
	
ex01numbers: ex01numbers.o
	$(CC) -o ex01 ex01numbers.o $(CFLAGS)

ex02sqrt: ex02sqrt.o
	$(CC) -o ex02 ex02sqrt.o $(CFLAGS)

ex02sqrt.o: ex02sqrt.c
	$(CC) -c ex02sqrt.c $(CFLAGS)


ex01numbers.o: ex01numbers.c
	$(CC) -c ex01numbers.c $(CFLAGS)

clean:
	rm -f $(OBJECTS) $(EXEC_NAME)

