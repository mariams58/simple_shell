#include "shell.h"
/**
  * main - checks prompt
  * @av: argument vector
  * @ac: argument count
  * @env: environmental variables
  *
  * Return: Always 0
  */
int main(int ac, char **av, char **env)
{
	char *cmd = NULL, *token[10];
	ssize_t rd;
	int i;

	if (ac)
	{
		while ((isatty(STDIN_FILENO) == 1))
		{
			print_out("($ ");
			rd = display_prompt(&cmd, av[ac - 1]);
			if (rd != -1)
			{
				get_tokens(cmd, token);
				i = execute_command(token, av[ac - 1], env);
				if (i == -1)
				{
					free(cmd);
					exit(EXIT_FAILURE);
				}
			}
		}
		display_prompt(&cmd, av[ac - 1]);
		get_tokens(cmd, token);
		execute_command(token, av[ac - 1], env);
	}
	free(cmd);
	exit(EXIT_SUCCESS);
	return (0);

}

/**
  * display_prompt - displays a prompt to std out to take input
  * @cmd: pointer to the command
  * @sh: name of the program
  *
  * Return: pinter to cmommand string
  */
ssize_t display_prompt(char **cmd, char *sh)
{
	size_t  bufsize = 0;
	ssize_t msg;

	msg = gt_line(cmd, &bufsize, sh);
	if (msg == 0 || (*cmd)[msg] == '\n')
		(*cmd)[msg] = '\0';
	if (msg == -1)
		perror(sh);
	return (msg);
}

/**
  * run_nshell - runs the shell in non interactive mode
  * @cmd: command array
  * @env: environmental variables
  *
  * Return: Nothing
  */
void run_nshell(char **cmd, char **env)
{

	if (cmd[0] != NULL)
	{
		if (feof(stdin))
		{
			print_out("\n");
			_exit(EXIT_SUCCESS);
		}
		if (execve(cmd[0], cmd, env) == -1)
		{
			perror(cmd[0]);
		}
	}
}
