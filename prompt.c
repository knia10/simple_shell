#include "shell.h"

/**
 * built_in - handles built-ins (exit, env, cd)
 * @token: user's typed command
 * @env: environmental variable
 * @num: take in nth user command typed to write error message
 * @lineptr: bring in command to free
 * Return: 1 if acted on builtin, 0 if not
 */
int built_in(char **token, list_t *env, int num, char **lineptr)
{
	int i = 0;

	if (_strcmp(token[0], "exit") == 0)
	{
		i = f_exit(token, env, num, lineptr);
	}
	else if (_strcmp(token[0], "env") == 0)
	{
		print_env(token, env);
		i = 1;
	}
	return (i);
}

/**
 * forget_space - return string without spaces in front
 * @str: pointer points to string
 * Return: new string
 */
char *forget_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * ctrl_D - Exits program
 * @i: chars read by getline
 * @lineptr: points to the command
 * @env: environmental variable linked list
 */
void ctrl_D(int i, char *lineptr, list_t *env)
{
	if (i == 0)
	{
		free(lineptr);
		free_linked_list(env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * f_prompt - Display a prompt and wait for the user to type a command.
 * @en: envrionmental variables
 * Return: 0 on success
 */
int f_prompt(char **en)
{
	list_t *env;
	size_t i = 0, n = 0;
	int command_line_nu = 0, exit_stat = 0;
	char *lineptr, *n_command, **token;

	env = linked_list_env_var(en);
	do {
		command_line_nu++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive_mode(env);

		signal(SIGINT, ctrl_C);
		lineptr = NULL;
		i = 0;
		i = _getline(&lineptr);
		ctrl_D(i, lineptr, env);
		n_command = lineptr;
		lineptr = forget_space(lineptr);
		n = 0;
		while (lineptr[n] != '\n')
			n++;
		lineptr[n] = '\0';
		if (lineptr[0] == '\0')
		{
			free(n_command);
			continue;
		}
		token = NULL;
		token = _string_tok(lineptr, " ");
		if (n_command != NULL)
			free(n_command);
		exit_stat = built_in(token, env, command_line_nu, NULL);
		if (exit_stat)
			continue;
		exit_stat = _execute(token, env, command_line_nu);
	} while (1);
	return (exit_stat);
}
