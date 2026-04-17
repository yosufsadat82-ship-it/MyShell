#ifndef SHELL_H
#define SHELL_H

#define MAX_INPUT  1024
#define MAX_ARGS   64
#define MAX_HISTORY 100

void run_shell();
int parse_input(char *input, char **args);
int execute(char **args);
int builtin_cmd(char **args);

#endif

