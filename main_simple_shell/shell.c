#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include <unistd.h>

int main()
{
    char *buffer = NULL, *duplicate_buffer;
    char **argv;
    ssize_t num_read;
    size_t n = 0;
    int num_tokens, int_mode;
    while (1)
    {

        int_mode = isatty(STDIN_FILENO);
        if (int_mode == 1)
            prompt();
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
            free(buffer);
            return (-1);
        }
        _strcpy(duplicate_buffer, buffer);
        num_tokens = count_token(duplicate_buffer, DELIM);
        argv = tokenize_line(buffer, DELIM, num_tokens);

        if (argv[0] != NULL)
            exec_argv(argv);
    }
    free(argv);
    free(buffer);
    free(duplicate_buffer);
}
