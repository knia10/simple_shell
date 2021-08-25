#include "shell.h"

/**
 * not_found - write error ("sh: 1: lss: not found")
 * @str: user's typed command
 * @c_n: nth user's typed command
 * @env: bring in environmental variables linked list to write shell name
 */
void not_found(char *str, int c_n, list_t *env)
{
	int count = 0;
	char *shell, *num;

	shell = get_env("_", env); /* obtener el nombre del shell para escribir */
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_str(c_n); /*convertir el númerode la línea de comandos en str*/
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}

/**
 * illegal_number - write error ("sh: 3: exit: Illegal number abc (or -1)")
 * @str: user's typed argument after the command: exit
 * @c_n: nth user's typed command
 * @env: bring in environ vars linked list to write shell name
 */
void illegal_number(char *str, int c_n, list_t *env)
{
	int count = 0;
	char *shell = NULL, *num = NULL;

	shell = get_env("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_str(c_n);
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, "\n", 1);
}
