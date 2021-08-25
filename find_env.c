#include "shell.h"

/**
 * find_env - find given environmental variable in linked list
 * @env: environmental variable linked list
 * @str: variable name
 * Return: idx of node in linked list
 */
int find_env(list_t *env, char *str)
{
	int j = 0, index = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == str[j]) /* Encuentra env var req */
			j++;
		if (str[j] == '\0') /* si coincide total/, break, return idx */
			break;
		env = env->next;
		index++;
	}
	if (env == NULL)
		return (-1);
	return (index);
}
