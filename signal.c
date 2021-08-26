#include "shell.h"

/**
 * ctrl_C - Prints ^C
 * @n: takes in int from signal
 */
void ctrl_C(int n __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n$ ", 3);
}
