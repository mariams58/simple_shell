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
	char *cmd = NULL;

	if (ac)
	{
		while ((isatty(STDIN_FILENO) == 1))
		{	print_out("($) ");
			cmd = display_prompt(&cmd, av[ac - 1]);
			execute_command(&cmd, av[ac - 1], env);
		}
		cmd = display_prompt(&cmd, av[ac - 1]);
		execute_command(&cmd, av[ac - 1], env);
		free(cmd);
	}
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
char *display_prompt(char **cmd, char *sh)
{
	size_t  bufsize = 0;
	ssize_t msg;

	msg = gt_line(cmd, &bufsize, sh);
	if (msg == -1)
	{
		free(cmd);
		if (feof(stdin))
		{
			print_out("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror(sh);
			exit(EXIT_FAILURE);
		}
	}
	return (*cmd);
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
		if (execve(cmd[0], cmd, env) == -1)
		{
			perror(cmd[0]);
		}
	}
}
