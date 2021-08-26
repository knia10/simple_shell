#include "shell.h"

/**
 * c_exit - frees user's typed command and linked list before exiting
 * @str: user's typed command
 * @env: input the linked list of envirnment
 */
void c_exit(char **str, list_t *env)
{
	free_pptr(str);
	free_linked_list(env);
	_exit(0);
}

/**
 * _execute - execute command typed into shell
 * @s: command user typed
 * @env: environmental variable
 * @num: nth user command; to be used in error message
 * Return: 0 on success
 */
int _execute(char **s, list_t *env, int num)
{
	char *p;
	int status = 0, t = 0;
	pid_t pid;

	if (access(s[0], F_OK) == 0)
	{
		p = s[0];
		t = 1;
	}

	else
		p = _which(s[0], env);

	if (access(p, X_OK) != 0)
	{
		not_found(s[0], num, env);
		free_pptr(s);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(p, s, NULL) == -1)
			{
				not_found(s[0], num, env);
				c_exit(s, env);
			}
		}
		else
		{
			wait(&status);
			free_pptr(s);
			if (t == 0)
				free(p);
		}
	}
	return (0);
}
