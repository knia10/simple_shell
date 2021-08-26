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

	/* obtiene/tokeniza los dir PATH, luego liberar string original */
	pth = get_env("PATH", env);
	toks = c_string_tok(pth, ":"); /* tokeniza los directorios en PATH */
	free(pth);		       /* c/dir esta delim por : */

	/* añade "/comnd" a cada token para ver si es legítimo */
	i = 0;
	while (toks[i] != NULL)
	{
		if (toks[i][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _strdup(toks[i]); /*cat: almacena name dir*/
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);    /*ej: bin/ls, str->ls*/
		if (access(cat, F_OK) == 0) /* encuentra la ruta? */
		{
			/* libera tokens antes de retornar el path */
			free_pptr(toks);
			return (cat);
		}
		free(cat); /* liberar string concat. si no se encuentra cmdo */
		i++;
	}
	free_pptr(toks);
	return (str); /* returna string si no es encontrado */
}
