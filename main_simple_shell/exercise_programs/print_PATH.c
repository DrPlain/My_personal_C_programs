#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
#include <unistd.h>

char **__environ;
void print_PATH(char *envVar, char *delim)
{
    char **tokenized_path = NULL;
    ssize_t num_substrings;
    ssize_t i = 0;
    char envVar_duplicate[1024];

    /*envVar_duplicate = malloc(sizeof(char) * 1024);
    if (envVar_duplicate = NULL)
    {
        printf("Malloc unable to create space\n");
        exit(EXIT_FAILURE);   
    }*/
    
    strcpy(envVar_duplicate, envVar);

    num_substrings = count_token(envVar_duplicate, delim);

    tokenized_path = malloc(sizeof(char *) * num_substrings);
    if (tokenized_path == NULL)
    {
        perror("Malloc unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    tokenized_path = tokenize_line(envVar, delim, num_substrings);

    while (tokenized_path[i] != NULL)
    {
        printf("%s\n", tokenized_path[i]);
        i++;
    }
    free(tokenized_path);
}