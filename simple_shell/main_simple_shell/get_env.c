#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

char **__environ;
char *_getenv(const char *name)
{
    int len, i = 0;

    if (name == NULL)
        return (NULL);
    len = strlen(name);
    
    while (__environ[i] != NULL)
    {
        if (strncmp(name, __environ[i], len) == 0)
        break;
        i++;
    }
    return (__environ[i]);
}