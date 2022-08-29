#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_token(char *buffer, char *delim)
{
    char *token;

    /* Number of tokens including the NULL token*/
    int count = 0;

    if (buffer == NULL)
        return (count);
    token = strtok(buffer, delim);
    count++;

    while (token != NULL)
    {
        token = strtok(NULL, delim);
        count++;
    }

    return (count);
}

char **tokenize_line(char *buffer, char *delim, int num_tokens)
{
    char *token = NULL;
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