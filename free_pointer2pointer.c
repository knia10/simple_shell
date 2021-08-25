#include "shell.h"

/**
 * free_pptr - free malloced arrays (pointer to pointer)
 * @str: array of strings
 */
void free_pptr(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
