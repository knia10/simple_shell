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

	/* si se lee "exit", libera los tokens de cmd y sale */
	if (_strcmp(token[0], "exit") == 0)
	{
		i = f_exit(token, env, num, lineptr);
	}
	/* si se lee "env", imprime env var, libera cmd tokens */
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
		if (isatty(STDIN_FILENO))		   /* comprobar si se refiere a la teminal */
			write(STDOUT_FILENO, "\n", 1); /* exit con nueva linea */
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
	size_t i = 0, n = 0; /* i: num. chars leídos x _getline*/
	int command_line_nu = 0, exit_stat = 0;
	char *lineptr, *n_command, **token;

	env = linked_list_env_var(en); /*almacena env var en list link */
	do {
		command_line_nu++;
		if (isatty(STDIN_FILENO)) /* modo interactivo */
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive_mode(env); /* si arg, modo no interactivo */

		signal(SIGINT, ctrl_C); /* SIGINT: nombre de la señal (No. 2) */
		lineptr = NULL;
		i = 0;					 /* resetea c/vez que corre el loop */
		i = _getline(&lineptr);	 /* lee comand en stdin */
		ctrl_D(i, lineptr, env); /* exits shell si ctrl-D */
		/* n_command almacena el string apuntado por lineptr */
		n_command = lineptr;
		lineptr = forget_space(lineptr);
		n = 0;
		while (lineptr[n] != '\n') /* hace recorrido del stream */
			n++;				   /* hasta que encuentre el \n */
		lineptr[n] = '\0';		   /*cuando llega al \n lo cambia por \0 */
		if (lineptr[0] == '\0') /* Imprime prompt si oprime solo enter */
		{
			free(n_command);
			continue;
		}
		token = NULL;					   /* Inicializa token */
		token = _string_tok(lineptr, " "); /* función strtok */
		if (n_command != NULL)
			free(n_command);
		exit_stat = built_in(token, env, command_line_nu, NULL);
		if (exit_stat)
			continue;
		exit_stat = _execute(token, env, command_line_nu);
	} while (1); /* keep on repeating till user exits shell */
	return (exit_stat);
}
