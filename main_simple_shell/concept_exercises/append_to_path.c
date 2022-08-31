#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include <string.h>

char *append_to_directory(char *directory, char ** argv, char *character)
{
    char *temp;
    int buff_size;
    if (directory == NULL)
        return (argv[0]);

    buff_size = (strlen(directory) + strlen(argv[0]) + 1);
    temp = malloc(sizeof(char) * buff_size);
    if (temp == NULL)
    {
        perror("malloc unable to allocate space\n");
        exit(EXIT_FAILURE);
    }
    _strcpy(temp, directory);
    strcat(temp, character);
    strcat(temp, argv[0]);

    return (temp);
}