#include "shell.h"

/**
 * t_strlen - returns token's string length for mallocing
 * @str: a token
 * @pos: index position in user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: token length
 */
int t_strlen(char *str, int pos, char delm)
{
	int len = 0;

	while ((str[pos] != delm) && (str[pos] != '\0'))
	{
		pos++; /* posición */
		len++; /* longitud del string */
	}
	return (len);
}

/**
 * n_delim - returns number of delim ignoring continuous delim
 * @str: user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: number of delims so that (num token = delims + 1)
 */
int n_delim(char *str, char delm)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == delm) && (str[i + 1] != delm))
		{
			/* maneja los delim continuos */
			num_delm++; /* contador */
		}
		if ((str[i] == delm) && (str[i + 1] == '\0'))
		{
			/*maneja los delim continuos después de string completo*/
			num_delm--;
		}
		i++;
	}
	return (num_delm);
}

/**
 * ignore_delm - returns a version of string without preceeding delims
 * @str: string
 * @delm: delimiter (e.g. " ")
 * Return: new string (e.g. "    ls -l" --> "ls -l")
 */
char *ignore_delm(char *str, char delm)
{
	while (*str == delm)
		str++;
	return (str);
}

/**
 * _string_tok - splits a str into substrings separated by delm
 * @str: The string brought from stdin
 * @delm: special separator (" ",:);
 * Return: an array of toks ("ls", "-l", "/tmp").
 */
char **_string_tok(char *str, char *delm)
{
	int sbuf = 0, p = 0, index = 0, i = 0, len = 0, z = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delm[0]; /* d_ch = " " */
	/* Crea un nuevo string, sin tener en cuenta los delimitadores*/
	str = ignore_delm(str, d_ch);
	/* malloc-ptrs almacenar un array de tokens(sbuf + 1),& NULL=ptr */
	sbuf = n_delim(str, d_ch); /* sbuf: Número de delimitadores */
	toks = malloc(sizeof(char *) * (sbuf + 2));
	if (toks == NULL)
		return (NULL);
	while (str[z] != '\0') /* Halla el indx del fin de string */
		z++;
	while (index < z)
	{ /* memoria -long para c/toks en la matriz */
		if (str[index] != d_ch)
		{
			len = t_strlen(str, index, d_ch); /* Tamaño de un token */
			toks[p] = malloc(sizeof(char) * (len + 1));
			if (toks[p] == NULL)
				return (NULL);
			i = 0;
			while ((str[index] != d_ch) && (str[index] != '\0'))
			{
				/*toks[p][i] matriz de punteros, c/u apunta a un token*/
				toks[p][i] = str[index];
				i++;
				index++;
			}
			toks[p][i] = '\0';
			t++;
		}
		/* manejar delim repetidos; incrementar ptr después ("ls __-l")*/
		if (index < z && (str[index + 1] != d_ch && str[index + 1] != '\0'))
			p++;
		index++;
	}
	p++;
	toks[p] = NULL; /* asigna un NULL al último ptr del array */
	return (toks);
}
