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