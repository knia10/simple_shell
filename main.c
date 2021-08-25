#include "shell.h"

/**
 * main - pathern function, Simple Shell
 * @argc: argument counter
 * @argv: arguments vector
 * @env: environment variable(s)
 * Return: 0 on success
 */
int main(int argc, char *argv[], char **env)
{
	(void)argc;
	(void)argv;

	f_prompt(env);
	return (0);
}
