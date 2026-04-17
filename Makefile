CC     = gcc
CFLAGS = -Wall -Wextra

all: myshell

myshell: main.c shell.c
	$(CC) $(CFLAGS) -o myshell main.c shell.c

clean:
	rm -f myshell

