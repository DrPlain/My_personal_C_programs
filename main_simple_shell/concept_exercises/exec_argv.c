#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "shell.h"
#include <string.h>

void exec_argv(char **argv)
{
    pid_t pid;
    char *command_exec;

    if (exec_buitin_commands(argv) == 0)
        return;

    command_exec = append_to_directory("/bin", argv, "/");

    pid = fork();
    if (pid == -1)
    {
        perror("Unable to create child process\n");
        return;
    }
    else if (pid == 0)
    {
        if (execve(command_exec, argv, __environ) == -1)
        {
            printf("%s: command not found\n", argv[0]);
            return;
        }
    }
    else
    {
        wait(NULL);
        free(command_exec);
    }
}
