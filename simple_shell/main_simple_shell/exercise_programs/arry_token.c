#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main()
{
    char *buffer =  NULL, *duplicate_buffer;
    char *delim = " \n\t";
    ssize_t num_read;
    size_t n = 0;
    ssize_t num_tokens = 0;
    char *token;
    char **arrTokens;
    int i = 0, j;

    printf("$ ");
    num_read = getline(&buffer, &n, stdin);
    duplicate_buffer = malloc(sizeof(char) * num_read);
    if (duplicate_buffer == NULL)
    {
        printf("Malloc unable to allocate space for duplicate_buffer\n");
        return (0);
    }
    strcpy(duplicate_buffer, buffer);

    token = strtok(buffer, delim);
    num_tokens++;

    while (token != NULL)
    {
        token = strtok(NULL, delim);
        num_tokens++;
    }
    token = strtok(duplicate_buffer, delim);

    arrTokens = malloc(sizeof(char *) * num_tokens);
    if (arrTokens == NULL)
    {
        perror("Malloc unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    while (token != NULL)
    {
        arrTokens[i] = token;
        token = strtok(NULL, delim);
        i++;
    }
    arrTokens[i] = NULL;

    j = 0;
    while (arrTokens[j] != NULL)
    {
        printf("%s\n", arrTokens[j]);
        j++;
    }

    return 0;
}