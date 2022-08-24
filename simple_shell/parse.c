#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *buffer = NULL, *duplicate_buffer = NULL;
    ssize_t num_read;
    size_t n = 0;
    char *token;
    const char *delim = " \\";
    int num_token, i = 0;
    char **argv;

    /* Setting up the prompt */
    printf("$ ");

    /* Reading from stdin and printing to stdout */
    /* Getline dynamically allocates space for our buffer */
    /* hence no need to do that ourselves */
    num_read = getline(&buffer, &n, stdin);

    /* getline returns -1 when ctrl D or EOF is encountered */
    if (num_read == -1)
    {
        printf("Exiting shell...");
        return (-1);
    }
    printf(">>> %s\n", buffer);

    /* Duplicate buffer because after call to strtok(), */ 
    /* string passed to it is destroyed */
    duplicate_buffer = malloc(sizeof(char) * num_read);
    if (duplicate_buffer == NULL)
    {
        printf("Malloc unable to allocate space for duplicate_buffer\n");
        return(0);
    }
    strcpy(duplicate_buffer, buffer);

    /* Tokenizing the string that was passed to stdin and */
    /* and finding the number of tokens generated (to know memory size to allocate) */
    token = strtok(buffer, delim);
    num_token = 1;
    while(token != NULL)
    {
        token = strtok(NULL, delim);/* NULL since we are parsing same string */
        num_token++;
    }
    
    /* Allocate space for **argv to store POINTERS tokenized strings */
    argv = malloc(sizeof(char *) * num_token);
    if (duplicate_buffer == NULL)
    {
        printf("Malloc unable to allocate space for argv\n");
        free(duplicate_buffer);
        return(0);
    }

    /* Get tokens and allocate space to save them in argv*/
    
    token = strtok(duplicate_buffer, delim);
    while (token != NULL)
    {
        argv[i] = malloc(sizeof(char) * strlen(token));
        if (duplicate_buffer == NULL)
        {
            printf("Malloc unable to allocate space for argv[%d]\n", i);
            free(duplicate_buffer);
            free(argv);
            return(0);
        }
        strcpy(argv[i], token);
        /* for debugging purposes */
        printf(">>> %s\n", argv[i]);
        /******************************/
        i++;
        token = strtok(NULL, delim);
    }
    argv[i] = NULL; /* argv should be NULL terminated from MAN */
    /* for debugging purposes */
        printf(">>> %s\n", argv[i]);
        printf("The user entered %d number(s) of token(s) including NULL\n", num_token);
        /******************************/
    while(i < num_token)
    {
        free(argv[i]);
        i++;
    }
    free(duplicate_buffer);
    free(argv);
    free(token);

    return (0);
}