#include "shell.h"

/**
 * c_n_delim - returns number of delim
 * @str: user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: number of tokens
 */
int c_n_delim(char *str, char delm)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if (str[i] == delm)
		{
			num_delm++;
		}
		i++;
	}
	return (num_delm);
}

/**
 * c_string_tok - toks a string even the continuous delim with empty string
 * (e.g. path --> ":/bin::/bin/usr" )
 * @str: user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: an array of tokens (e.g. {"\0", "/bin", "\0", "/bin/usr"}
 * (purpose is to have which command look through current directory if ":")
 */
char **c_string_tok(char *str, char *delm)
{
	int sbuf = 0, p = 0, si = 0, i = 0, len = 0, se = 0;
	char **toks = NULL, d_ch;

	/* set variable to be delimeter character (" ") */
	d_ch = delm[0];
	/* malloc number of ptrs to store array of tokens, and NULL ptr */
	sbuf = c_n_delim(str, d_ch);
	toks = malloc(sizeof(char *) * (sbuf + 2));
	if (toks == NULL)
		return (NULL);

	/* iterate from string index 0 to string ending index */
	while (str[se] != '\0')
		se++;
	while (si < se)
	{
		/* malloc lengths for each token ptr in array */
		len = t_strlen(str, si, d_ch);
		toks[p] = malloc(sizeof(char) * (len + 1));
		if (toks[p] == NULL)
			return (NULL);
		i = 0;
		while ((str[si] != d_ch) &&
			   (str[si] != '\0'))
		{
			toks[p][i] = str[si];
			i++;
			si++;
		}
		toks[p][i] = '\0'; /* null terminate at end*/
		p++;
		si++;
	}
	toks[p] = NULL; /* set last array ptr to NULL */
	return (toks);
}
