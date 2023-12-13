#ifndef _SHELL_H_
#define _SHELL_H_

#define MAX_BUFF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int print_out(char *str);
ssize_t gt_line(char **lineptr, size_t *n, char *sh);
void run_nshell(char **cmd, char **env);
int execute_command(char **token, char *sh, char **env);
int get_tokens(char *cmd, char **args);
void free_arr(char **arr);
char *display_prompt(char **cmd, char *sh);

#endif
