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

/**
 * struct bin_func - Struct for shell built-i functions
 *
 * @str: The operator
 * @func: The function associated
 */
typedef struct bin_func
{
	char *str;
	int (*func)(char **token);
} ar_bin;

int print_out(char *str);
ssize_t gt_line(char **lineptr, size_t *n, char *sh);
void run_nshell(char **av, char **env);
int execute_command(char **token, char *sh, char **env);
ssize_t gt_str(char **lineptr, size_t *n, char *sh);
int get_tokens(char *cmd, char **args, char *delim);
void free_arr(char **arr);
ssize_t display_prompt(char **cmd, char *sh);

#endif
