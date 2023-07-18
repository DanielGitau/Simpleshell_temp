#include "main.h"

/**
 * _env - Prints the current environment variables.
 */
void _env(void)
{
	char **env = environ;
	/* Assign the global environment variable array to a local variable */

    /* Iterate over each environment variable and print them */
	while (*env)
	{
	put_s(*env);
		_putchar('\n');
	env++;
	}
}

/**
 * exit_func - Performs the exit functionality of the shell
 * @argv: The array of command arguments.
 * @copy_cmd:  A copy of the command string.
 * @full_cmd: The full command string.
 * @num_tokn: The number of tokens in the command
 */
void exit_func(char **argv, char *copy_cmd, char *full_cmd, int num_tokn)
{
	int counter, status = 0;

	free(full_cmd);
	free(copy_cmd);
	if (argv[1] != NULL)
		status = atoi(argv[1]);

	for (counter = 0; counter < num_tokn; counter++)
		free(argv[counter]);
	free(argv);
	exit(status);
}

