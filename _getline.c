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

	/* leer mientras haya stdin > buffsize; -1 para '\0' */
	while (no_cmd == 0 && (i = read(STDIN_FILENO, buffer, 1024 - 1)))
	{
		if (i == -1) /* check si hubo error en la lectura */
			return (-1);
		/* i: número de chars leídos en stdin */
		buffer[i] = '\0'; /* terminar el buffer con \0 para usarlo _strcat */

		n = 0; /* último bucle si se encuentra \n en la lectura de stdin */
		while (buffer[n] != '\0')
		{
			if (buffer[n] == '\n')
				no_cmd = 1;
			n++;
		}

		/* copiar lo leído en el buffer de getline */
		if (t == 0) /* malloc la primera vez */
		{
			/* i++; */
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buffer);
			size = i;
			t = 1; /* t contador de uso malloc */
		}
		else /* reasignar con _strcat con cada bucle */
		{
			size += i; /* size = size + i */
			*str = _strcat(*str, buffer);
		}
	}
	return (size);
}
