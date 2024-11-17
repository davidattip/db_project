CC = gcc
CFLAGS = -Wall -Wextra -g

all: main

main: src/main.o src/btree.o src/repl.o
	$(CC) $(CFLAGS) -o main src/main.o src/btree.o src/repl.o

src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/btree.o: src/btree.c
	$(CC) $(CFLAGS) -c src/btree.c -o src/btree.o

src/repl.o: src/repl.c
	$(CC) $(CFLAGS) -c src/repl.c -o src/repl.o

clean:
	rm -f src/*.o main tests
