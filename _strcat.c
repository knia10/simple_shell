#include "shell.h"

/**
 * _strcat - concatenate two strings
 * @dest: This is pointer to the destination array
 * @src: This is the string to be appended
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int l_dest = 0; /* length dest */
	int l_src = 0;  /* length src */
	int len = 0;    /* total len = desr + src */
	int j = 0;

	/* Encentra long total de string concat para _realloc */
	while (dest[l_dest] != '\0')
	{
		l_dest++;
		len++;
	}
	while (src[l_src] != '\0')
	{
		l_src++;
		len++;
	}

	/* malloc para dest fuera de la func, por eso realloc */
	dest = _realloc(dest, l_dest, sizeof(char) * len + 1);

	while (src[j] != '\0')
	{
		dest[l_dest] = src[j]; /* concatena src a dest */
		l_dest++;
		j++;
	}
	dest[l_dest] = '\0';

	return (dest);
}
