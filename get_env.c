#include "shell.h"

/**
 * c_strdup - duplicate a string
 * @str: string to duplicate (env var PATH=/bin:/bin/ls)
 * @s: number of bytes to exclude ("PATH=")
 * Return: string (/bin:/bin/ls)
 */
char *c_strdup(char *str, int s)
{
	char *copied_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + len))
		len++;
	len++;

	copied_str = malloc(sizeof(char) * (len - s));
	if (copied_str == NULL)
		return (NULL);

	i = 0;
	while (i < (len - s))
	{
		*(copied_str + i) = *(str + s + i);
		i++;
	}
	return (copied_str);
}

/**
 * get_env - finds and returns a copy of the requested env var
 * @str: string to store it in
 * @env: entire set of environmental variables
 * Return: copy of requested environmental variable
 */
char *get_env(char *str, list_t *env)
{
	int j = 0, s = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == str[j])
			j++;
		if (str[j] == '\0' && (env->var)[j] == '=')
			break;
		env = env->next;
	}

	while (str[s] != '\0')
		s++;
		s++;
	return (c_strdup(env->var, s));
}
