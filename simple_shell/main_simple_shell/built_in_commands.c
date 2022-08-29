#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void my_exit(char **argv)
{
    if (argv != NULL)
        exit(0);
}

void cd(char **argv)
{
    if (argv[1] == NULL)
    {
        perror("cd: missing argument\n");
    }
    else
    {
        if (chdir(argv[1]) != 0)
        {
            perror("shell: cd\n");
        } 
    }
}

void help(char **argv)
{
    char *helpText =
        "The following commands are available:\n"
        "  cd       Change the working directory.\n"
        "  exit     Exit the shell.\n"
        "  help     Print this help text.\n"
        ;
    if (argv != NULL)
        printf("%s\n", helpText);
}