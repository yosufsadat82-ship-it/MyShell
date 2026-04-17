#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

int parse_input(char *input, char **args)
{
    int i = 0;
    args[i] = strtok(input, " \t\n");
    while (args[i] != NULL && i < MAX_ARGS - 1)
    {
        i++;
        args[i] = strtok(NULL, " \t\n");
    }
    return i;
}

int builtin_cmd(char **args)
{
    if (args[0] == NULL)
        return 1;
    if (strcmp(args[0], "exit") == 0)
        exit(0);
    if (strcmp(args[0], "cd") == 0)
    {
        if (args[1] == NULL)
            chdir(getenv("HOME"));
        else
            chdir(args[1]);
        return 1;
    }
    if (strcmp(args[0], "help") == 0)
    {
        printf("MyShell - commands: cd, exit, help\n");
        return 1;
    }
    return 0;
}

int execute(char **args)
{
    pid_t pid;
    int status;

    if (builtin_cmd(args))
        return 1;

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
            perror("myshell");
        exit(1);
    }
    else
        waitpid(pid, &status, 0);
    return 1;
}

void run_shell()
{
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1)
    {
        printf("\033[1;32mmyshell>\033[0m ");
        fflush(stdout);
        if (fgets(input, MAX_INPUT, stdin) == NULL)
            break;

        add_history(input);

        if (parse_input(input, args) == 0)
            continue;
        execute(args);
    }
}

