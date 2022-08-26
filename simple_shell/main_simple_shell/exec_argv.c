#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

char **__environ;

void exec_argv(char **argv)
{
    int status;
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("Unable to create child process\n");
        return;
    }
    else if (pid == 0)
    {
        if (execve(argv[0], argv, __environ) == -1)
        {
            printf("Command %s: Not found\n", argv[0]);
            exit(EXIT_FAILURE);
        };
        
    }
    else
    {
        if (wait(&status) == -1)
            perror("wait failed\n");
    }
}