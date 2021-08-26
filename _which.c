#include "shell.h"

/**
 * _which - fleshes out command by appending it to a matching PATH directory
 * @str: first command typed into shell (typed "ls -l" --> "ls")
 * @env: environmental variable
 * Return: a copy of fleshed out command ("/bin/ls" if originally "ls")
 */
char *_which(char *str, list_t *env)
{
	char *pth, *cat = NULL, **toks;
	int i = 0;

	pth = get_env("PATH", env);
	toks = c_string_tok(pth, ":");
		free(pth);

	i = 0;
	while (toks[i] != NULL)
	{
		if (toks[i][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _strdup(toks[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			free_pptr(toks);
			return (cat);
		}
		free(cat);
		i++;
	}
	free_pptr(toks);
	return (str);
}
