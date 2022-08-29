#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main()
{
    while (1)
    {
        char *buffer = NULL, *duplicate_buffer;
        char *delim = " \n\t";
        char **argv;
        ssize_t num_read;
        size_t n = 0;
        int num_tokens;

        printf("$ ");
        num_read = getline(&buffer, &n, stdin);
        if (num_read < 0)
        {
            perror("Error reading line\n");
            exit(EXIT_FAILURE);
        }

        duplicate_buffer = malloc(sizeof(char) * num_read);
        if (duplicate_buffer == NULL)
        {
            perror("Malloc unable to allocate memory\n");
            return (-1);
        }
        strcpy(duplicate_buffer, buffer);

        num_tokens = count_token(duplicate_buffer, delim);
        argv = tokenize_line(buffer, delim, num_tokens);

        if (argv[0] != NULL)
        {
            exec_argv(argv);
        }
        free(argv);
        free(buffer);
        free(duplicate_buffer);
    }
}