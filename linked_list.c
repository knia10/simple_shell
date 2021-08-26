#include "shell.h"

/**
 * print_list - print linked list
 * @h: linked list
 * Return: size of linked list
 */
size_t print_list(list_t *h)
{
	list_t *c_list = h;
	int count = 0;
	int c = 0;

	if (h == NULL)
		return (0);
	while (c_list != NULL)
	{
		if (c_list->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			c = 0;
			while ((c_list->var)[c] != '\0')
				c++;
			write(STDOUT_FILENO, c_list->var, c);
			write(STDOUT_FILENO, "\n", 1);
		}
		c_list = c_list->next;
		count++;
	}
	return (count);
}

/**
 * new_node - add node at the end of inked list
 * @head: pointer to head of linked list
 * @str: data to new node
 * Return: pointer to new linked list
 */
list_t *new_node(list_t **head, char *str)
{
	list_t *new;
	list_t *p;

	if (head == NULL || str == NULL)
		return (NULL);
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->var = _strdup(str);
	new->next = NULL;
	p = *head;
	if (p != NULL)
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = new;
	}
	else
	{
		*head = new;
	}
	return (*head);
}

/**
 * free_linked_list - frees linked list
 * @list: linked list
 */
void free_linked_list(list_t *list)
{
	list_t *p;

	while (list != NULL)
	{
		p = list;
		list = list->next;
		free(p->var);
		free(p);
	}
}
