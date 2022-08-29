#include <stdlib.h>
#include "shell.h"
#include <string.h>

char **__environ;

void exec_argv(char **argv)
{
    int status, i;
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("Unable to create child process\n");
        return;
    }
    else if (pid == 0)
    {
        execve(argv[0], argv, __environ);
        printf("%s: command not found\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        do
         waitpid(pid, &status, WUNTRACED);
        while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}