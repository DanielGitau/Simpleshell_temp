#include "main.h"

/**
 * _get_sigint - Handle the crtl + c call in prompt
 * @signal: Signal handler
 */
void _get_sigint(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
