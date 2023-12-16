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
	char *token[10], *cmd = NULL, *args[10];
	ssize_t read, i;
	size_t len = 0;
	int y = 0, x;

	if (ac)
	{
		while ((isatty(STDIN_FILENO) == 1))
			run_nshell(av, env);
		read = gt_str(&cmd, &len, av[ac - 1]);
		if (read == -1)
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		for (i = 0; i != read - 1; i++)
		{
			if (cmd[i] == '\n')
			{
				x = get_tokens(cmd, args, "\n\t\v");
				if (x > 1)
				{
					while (args[y] != NULL)
					{
						get_tokens(args[y], token, " \n\t\v");
						execute_command(token, av[ac - 1], env);
						y++;
					}
					exit(EXIT_SUCCESS);
				}
			}

		}
		get_tokens(cmd, token, " \n\t\v");
		execute_command(token, av[ac - 1], env);
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
ssize_t display_prompt(char **cmd, char *sh)
{
	size_t  bufsize = 0;
	ssize_t msg;

	msg = gt_line(cmd, &bufsize, sh);
	if ((*cmd)[msg] == '\n')
		(*cmd)[msg] = '\0';
	if (msg == -1)
	{
		perror(sh);
	}
	return (msg);
}

/**
  * run_nshell - runs the shell in non interactive mode
  * @av: command array
  * @env: environmental variables
  *
  * Return: Nothing
  */
void run_nshell(char **av, char **env)
{
	int i = 1;
	ssize_t rd;
	char *cmd = NULL, *token[10];

	print_out("($ ");
	rd = display_prompt(&cmd, av[0]);
	if (rd >= 1)
	{
		get_tokens(cmd, token, " \n\t\v");
		if (token[0] != NULL)
			i = execute_command(token, av[0], env);
		if (i == -1)
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	free(cmd);
}
