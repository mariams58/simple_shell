#include "shell.h"
/**
  * execute_command - executes command in interactive mode
  * @token: command args
  * @sh: name of program
  * @env: environmental variables
  *
  */
int execute_command(char **token, char *sh, char **env)
{
	pid_t ch_pid;
	int status;
	char *str = token[0];
	char *argv[2];

	argv[0] = str;
	argv[1] = NULL;
	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror(sh);
	}
	else if (ch_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror(sh);
			return (-1);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
