#include <stdio.h>
#include "shell.h"

/* exec_builtin_commands - executes command argv[0] if its built in
 * @argv: An array of strings containing commands to execute
 * Return: 0 on sucess and -1 if command is not a built in function
 */

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