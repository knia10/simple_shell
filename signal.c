#include "shell.h"

/**
 * ctrl_C - shell should not quit when the user inputs ^C
 * @n: takes in int from signal
 */
void ctrl_C(int n __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n$ ", 3);
}
