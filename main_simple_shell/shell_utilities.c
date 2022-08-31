#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "shell.h"

void prompt()
{
    char cwd[1024], *username;

    getcwd(cwd, sizeof(cwd));
    username = _getenv("USER");
    printf("@%s:", username);
    printf("%s$ ", cwd);
}

char *_getenv(const char *name)
{
    int len, i = 0;

    if (name == NULL)
        return (NULL);
    len = _strlen(name);
    
    while (__environ[i] != NULL)
    {
        if (_strncmp(name, __environ[i], len) == 0)
        break;
        i++;
    }
    return (__environ[i]);
}

char **tokenize_PATH(char *envVar, char *delim)
{
    char **tokenized_path = NULL;
    ssize_t num_substrings;
    char envVar_duplicate[1024];
    
    _strcpy(envVar_duplicate, envVar);
    num_substrings = count_token(envVar_duplicate, delim);

    tokenized_path = malloc(sizeof(char *) * num_substrings);
    if (tokenized_path == NULL)
    {
        perror("Malloc unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    tokenized_path = tokenize_line(envVar, delim, num_substrings);

    return (tokenized_path);
}

char *append_to_directory(char *directory, char ** argv, char *character)
{
    char *temp;
    int buff_size;
    if (directory == NULL)
        return (argv[0]);

    buff_size = (_strlen(directory) + _strlen(argv[0]) + 1);
    temp = malloc(sizeof(char) * buff_size);
    if (temp == NULL)
    {
        perror("malloc unable to allocate space\n");
        exit(EXIT_FAILURE);
    }
    _strcpy(temp, directory);
    _strcat(temp, character);
    _strcat(temp, argv[0]);

    return (temp);
}

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