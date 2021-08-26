#include "shell.h"

/**
 * linked_list_env_var - creates a linked list - env vars
 * @env: enviromental variables
 * Return: linked list
 */
list_t *linked_list_env_var(char **env)
{
	list_t *head;
	int i = 0;

	head = NULL;
	while (env[i] != NULL)
	{
		new_node(&head, env[i]);
		i++;
	}
	return (head);
}

/**
 * print_env - prints environmental variables
 * @str: user's command into shell ("env")
 * @env: environmental variables
 * Return: 0 on success
 */
int print_env(char **str, list_t *env)
{
	free_pptr(str);
	print_list(env);
	return (0);
}
