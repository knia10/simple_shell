#include "shell.h"

/**
 * _strcat - concatenate two strings
 * @dest: This is pointer to the destination array
 * @src: This is the string to be appended
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int l_dest = 0;
	int l_src = 0;
	int len = 0;
	int j = 0;

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

	dest = _realloc(dest, l_dest, sizeof(char) * len + 1);

	while (src[j] != '\0')
	{
		dest[l_dest] = src[j];
		l_dest++;
		j++;
	}
	dest[l_dest] = '\0';

	return (dest);
}
