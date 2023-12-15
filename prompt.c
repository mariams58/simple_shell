#include "shell.h"
/**
  * gt_line - a version of the c etline function
  * @lineptr: pointer to the address of text read
  * @n: size of text to rread
  * @sh: name of program executable
  * Return: Amount of chars read without the null byte
  */
ssize_t gt_line(char **lineptr, size_t *n, char *sh)
{
	ssize_t rd;
	size_t buf_size = MAX_BUFF_SIZE, p = 0;

	if (*lineptr == NULL)
	{
		*lineptr = malloc(sizeof(char) * buf_size);
		if (*lineptr == NULL)
			return (-1);
	}
	while (1)
	{
		rd = read(STDIN_FILENO, &(*lineptr)[p], 1);
		if (rd == -1)
		{
			perror(sh);
			exit(EXIT_FAILURE);
		}
		if (rd == 0 || ((*lineptr)[p] == '\n'))
		{
			(*lineptr)[p] = '\0';
			break;
		}
		p++;
	}
	*n = p;
	return (p);
}

/**
  * print_out - prints out to dtsout
  * @str: pointer to str
  *
  * Return: amount of chars printed
  */
int print_out(char *str)
{
	return (write(STDOUT_FILENO, str, strlen(str)));
}

/**
  * get_tokens - tokenisez the cmd line from user
  * @cmd: pointer to command string
  * @args: argument array
  *
  * Return: an array of string
  */
int get_tokens(char *cmd, char **args)
{
	char *token = NULL;
	int x = 0;

	if (cmd != NULL)
		token = strtok(cmd, " \n\t\v");
	while (token != NULL)
	{
		args[x] = token;
		x++;
		token = strtok(NULL, " \n\t\v");
	}
	args[x++] = NULL;
	return (x);
}
