#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

void my_exit(char **argv)
{
    if (argv != NULL)
        exit(0);
}

void cd(char **argv)
{
    if (argv[1] == NULL)
        perror("cd: missing argument\n");
    else{
        if (chdir(argv[1]) != 0)
            perror("shell: cd\n");
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

int exec_buitin_commands(char **argv)
{
    int builtin_size, i;
    struct builtins my_builtin[] = {
        {"exit", my_exit},
        {"cd", cd},
        {"help", help},
    };

    builtin_size = sizeof(my_builtin) / sizeof(struct builtins);

    for (i = 0; i < builtin_size; i++)
    {
        if (_strcmp(argv[0], my_builtin[i].command) == 0)
        {
            my_builtin[i].func(argv);
            return (0);
        }
    }
    return (-1);
}
 