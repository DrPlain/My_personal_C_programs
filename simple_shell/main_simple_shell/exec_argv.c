#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "shell.h"
#include <string.h>

char **__environ;

void exec_argv(char **argv)
{
    int status, i;
    pid_t pid;
    int builtin_size;
    struct builtins my_builtin[] = {
        {"exit", my_exit},
        {"cd", cd},
        {"help", help},
    };

    builtin_size = sizeof(my_builtin)/sizeof(struct builtins);

    for (i = 0; i < builtin_size; i++)
    {
        if (_strcmp(argv[0], my_builtin[i].command) == 0)
        {
            my_builtin[i].func(argv);
            return;
        }

    }

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
         waitpid(pid, &status, WUNTRACED);
        while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}