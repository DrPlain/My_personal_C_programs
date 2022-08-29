#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char **argv;
    argv = malloc(sizeof(char*) * )

    char *name[] = {"Gideon", "Ebuka", "Brenda", NULL};
    
    int i = 0;
    while (name[i] != NULL)
    {
        printf("%s\n", name[i]);
        i++;
    }
    return 0;
}