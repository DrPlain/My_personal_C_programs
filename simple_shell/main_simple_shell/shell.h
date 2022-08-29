#ifndef _MAIN_H_
#define _MAIN_H_

int count_token(char *buffer, char *delim);
char **tokenize_line(char *buffer, char *delim, int num_tokens);
void exec_argv(char **argv);
char *_getenv(const char *name);
void print_PATH(char *envVar, char *delim);

struct builtins
{
    char *command;
    void (*func)(char **);
};

int builtin_size();
void my_exit(char **argv);
void cd(char **argv);
void help(char **argv);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
#endif
