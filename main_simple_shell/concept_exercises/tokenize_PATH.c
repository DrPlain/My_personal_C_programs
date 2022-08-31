#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include <string.h>
#include <unistd.h>

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