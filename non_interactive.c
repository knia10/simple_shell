#include "shell.h"

/**
 * c_forget_space - custom ignores spaces and newlines
 * (echo "ls\n ls" | ./a.out)
 * @str: envrionmental variables
 * Return: new string
 */
char *c_forget_space(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 * non_interactive_mode - handles pipes commands into shell via pipeline
 * example: echo "ls -la" | ./hsh
 * @env: envrionmental variables
 */
void non_interactive_mode(list_t *env)
{
	size_t i = 0, n = 0;
	int command_line_nu = 0, exit_stat = 0;
	char *lineptr = NULL, *n_command = NULL, **n_line, **token;

	i = _getline(&lineptr);
	if (i == 0)
	{
		free(lineptr);
		exit(0);
	}
	n_command = lineptr;
	lineptr = c_forget_space(lineptr);
	n_line = _string_tok(lineptr, "\n");
	if (n_command != NULL)
		free(n_command);
	n = 0;
	while (n_line[n] != NULL)
	{
		command_line_nu++;
		token = NULL;
		token = _string_tok(n_line[n], " ");
		exit_stat = built_in(token, env, command_line_nu, n_line);
		if (exit_stat)
		{
			n++;
			continue;
		}
		exit_stat = _execute(token, env, command_line_nu);
		n++;
	}
	free_pptr(n_line);
	free_linked_list(env);
	exit(exit_stat);
}
