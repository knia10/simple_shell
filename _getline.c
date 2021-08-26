#include "shell.h"

/**
 * _getline - stores into malloced buffer the user's command into shell
 * @str: buffer
 * Return: number of characters read
 */
size_t _getline(char **str)
{
	ssize_t i = 0, size = 0, t = 0, no_cmd = 0, n = 0;
	char buffer[1024];

	while (no_cmd == 0 && (i = read(STDIN_FILENO, buffer, 1024 - 1)))
	{
		if (i == -1)
			return (-1);
		buffer[i] = '\0';
		n = 0;
			while (buffer[n] != '\0')
		{
			if (buffer[n] == '\n')
				no_cmd = 1;
			n++;
		}

		if (t == 0)
		{
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buffer);
			size = i;
			t = 1;
		}
		else
		{
			size += i;
			*str = _strcat(*str, buffer);
		}
	}
	return (size);
}
