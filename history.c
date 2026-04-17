#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

static char history[MAX_HISTORY][MAX_INPUT];
static int  hist_count = 0;

void add_history(char *cmd)
{
    if (cmd == NULL || cmd[0] == '\0')
        return;
    strncpy(history[hist_count % MAX_HISTORY], cmd, MAX_INPUT - 1);
    hist_count++;
}

void print_history(void)
{
    int start = 0;
    if (hist_count > MAX_HISTORY)
        start = hist_count - MAX_HISTORY;
    for (int i = start; i < hist_count; i++)
        printf("%d  %s\n", i + 1, history[i % MAX_HISTORY]);
}

char *get_history_entry(int n)
{
    if (n < 1 || n > hist_count)
        return NULL;
    return history[(n - 1) % MAX_HISTORY];
}

