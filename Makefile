CC     = gcc
CFLAGS = -Wall -Wextra

all: myshell

myshell: main.c shell.c history.c
	$(CC) $(CFLAGS) -o myshell main.c shell.c history.c redirection.c pipe.c

clean:
	rm -f myshell

