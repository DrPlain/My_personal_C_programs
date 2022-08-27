#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main()
{
    char *buffer =  NULL, *duplicate_buffer;
    char *delim = " \n\t";
    char **argv;
    ssize_t num_read;
    size_t n = 0;
    int num_tokens;

    while (1)
    {
        printf("$ ");
        num_read = getline(&buffer, &n, stdin);
        duplicate_buffer = malloc(sizeof(char) * num_read);
        if (duplicate_buffer == NULL)
        {
            printf("Malloc unable to allocate space for duplicate_buffer\n");
            return (0);
        }
        strcpy(duplicate_buffer, buffer);

        num_tokens = count_token(duplicate_buffer, delim);
        argv = tokenize_line(buffer, delim, num_tokens);

        /* FOR DEBUGGING PURPOSES */
        /*int i = 0;
        printf("*************************************\n");
        printf("Number of tokens including NULL is %d\n\n", num_tokens);
        while (argv[i] != NULL)
        {

            printf("%s\n", argv[i]);
            i++;
        }
        printf("*************************************\n");
        */

        if (argv[0] != NULL)
        {
            exec_argv(argv);
        }

        free(argv);
        free(buffer);
        free(duplicate_buffer);
    }

    return (0);
}