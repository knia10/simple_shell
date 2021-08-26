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

	/* comprueba el archivo por el nombre de ruta apuntado por PATH */
	if (access(s[0], F_OK) == 0) /* F_OK: comprueba existe el file */
	{
		p = s[0];
		t = 1;
	}
	/* si no... */
	else
		p = _which(s[0], env);

	if (access(p, X_OK) != 0) /* si no es un ejecutable, libera */
	{
		not_found(s[0], num, env);
		free_pptr(s);
		return (127); /* el comando no se encuentra en el PATH */
	}
	else /* si si, bifurca proceso y ejecuta el comando */
	{
		pid = fork();
		if (pid == 0) /* si el proceso es proc hijo, ejecuta */
		{
			if (execve(p, s, NULL) == -1)
			{
				not_found(s[0], num, env); /* special err msg */
				c_exit(s, env);
			}
		}
		else /* si el padre, espera al hijo y luego libera todo */
		{
			wait(&status);
			free_pptr(s);
			if (t == 0)
				free(p);
		}
	}
	return (0);
}
