#ifndef _MAIN_H_
#define _MAIN_H_

int count_token(char *buffer, char *delim);
char **tokenize_line(char *buffer, char *delim, int num_tokens);
void exec_argv(char **argv);

#endif
