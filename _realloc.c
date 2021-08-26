#include "shell.h"

/**
 * _realloc - allocate memory and set all values to 0
 * @ptr: pointer to the memory previously allocated (malloc(old_size))
 * @old_size: size previously allocated
 * @new_size: new size to reallocate
 * Return: pointer to reallocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i;

	if (new_size == 0 && ptr != NULL) /* NO necesita reasignar memoria */
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size) /* retorna ptr si new = old */
		return (ptr);

	if (ptr == NULL) /* nuevo tamaño si ptr es originalmente null */
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		else
			return (p);
	}

	p = malloc(new_size); /* comprobar error */
	if (p == NULL)
		return (NULL);

	/* rellenar los valores -> tamaño old o new */
	for (i = 0; i < old_size && i < new_size; i++)
		*((char *)p + i) = *((char *)ptr + i);
	free(ptr);

	return (p);
}
