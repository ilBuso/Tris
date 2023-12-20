# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Target and dependencies
tris: main.o
	$(CC) $(CFLAGS) -o tris main.o

# Dependency and command
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Clean rule
clean:
	rm -f tris main.o