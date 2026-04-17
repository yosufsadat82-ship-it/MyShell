#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

int handle_pipe(char **args)
{
    int i = 0;
    int pipe_pos = -1;

    while (args[i] != NULL)
    {
        if (strcmp(args[i], "|") == 0)
        {
            pipe_pos = i;
            break;
        }
        i++;
    }
    if (pipe_pos == -1)
        return 0;

    args[pipe_pos] = NULL;
    char **left  = args;
    char **right = args + pipe_pos + 1;

    int fd[2];
    pipe(fd);

    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execvp(left[0], left);
        perror("myshell");
        exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execvp(right[0], right);
        perror("myshell");
        exit(1);
    }

    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 1;
}

