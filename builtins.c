#include "main.h"

void _env()
{
	char **env = environ;  /* Assign the global environment variable array to a local variable */

    /* Iterate over each environment variable and print them */
    while (*env) {
        put_s(*env);
		_putchar('\n');
        env++;
    }
}
void exit_func(char **argv, char *copy_command, char *full_command, int num_tokens)
{
	int counter, status = 0;

	free(full_command);
	free(copy_command);
	if (argv[1] != NULL)
		status = atoi(argv[1]);

	for (counter = 0; counter < num_tokens; counter++)
		free(argv[counter]);
	free(argv);
	exit(status);
}

