CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: hello

hello: hello.c
	$(CC) $(CFLAGS) -o hello hello.c

run: hello
	./hello

clean:
	rm -f hello.exe