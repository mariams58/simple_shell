#include "shell.h"
/**
  * execute_command - executes command in interactive mode
  * @token: command args
  * @sh: name of program
  * @env: environmental variables
  *
  * Return: int value
  */
int execute_command(char **token, char *sh, char **env)
{
	pid_t ch_pid;
	int status;

	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror(sh);
	}
	else if (ch_pid == 0)
	{
		if (execve(token[0], token, env) == -1)
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
