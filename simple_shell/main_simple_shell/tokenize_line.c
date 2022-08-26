#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **tokenize_line(char *buffer, char *delim, int num_tokens)
{
    char *token;
    char **argv;
    int i = 0;

    argv = malloc(sizeof(char *) * num_tokens);
    if (argv == NULL)
    {
        perror("Malloc unable to allocate space\n");
        exit(EXIT_FAILURE);
    }
    
    token = strtok(buffer, delim);

    while (token != NULL)
    {
        argv[i] = token;
        i++;
        token = strtok(NULL, delim);
    }
    argv[i] = NULL;
    
    return (argv);
}