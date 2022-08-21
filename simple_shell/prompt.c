#include <stdio.h>

int main(void)
{
    char *buffer = NULL;
    ssize_t num_read;
    size_t n = 0;

    printf("$ ");
    num_read = getline(&buffer, &n, stdin);
    printf(">>> %s", buffer);

    return (0);
}