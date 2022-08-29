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

    free(token);
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
        free(buffer);
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

/**
 * _strcpy - copies the string pointed to src to dest including \0
 * @src: pointer to source string
 * @dest: destination buffer
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	char *aux = dest;

	while (*src)
		*dest++ = *src++;
	return (aux);
}

/**
 * _strcmp - A function that works exactly like strcmp
 * @s1: First string
 * @s2: Second string
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}