#include "shell.h"

/**
 * c_atoi - converts the string into an integer
 * @str: string
 * Return: number if success, -1 if string contains non-numbers
 */
int c_atoi(char *str)
{
	int i = 0;
	unsigned int num = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			num = num * 10 + (str[i] - 48);
		if (str[i] > 57 || str[i] < 48)
			return (-1);
		i++;
	}
	return (num);
}

/**
 * f_exit - cause process termination
 * @str: user's command into shell
 * @env: environmental variable
 * @num: int
 * @lineptr: the command
 * Return: 0 if success 2 if fail
 */
int f_exit(char **str, list_t *env, int num, char **lineptr)
{
	int value = 0;

	if (str[1] != NULL)
		value = c_atoi(str[1]);

	if (value == -1)
	{
		illegal_number(str[1], num, env);
		free_pptr(str);
		return (2);
	}
	free_pptr(str);
	free_linked_list(env);
	if (lineptr != NULL)
		free_pptr(lineptr);
	exit(value);
}
