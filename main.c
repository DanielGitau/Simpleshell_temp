#include "main.h"
/**
 * main - The entry point of the program.
 * Return: returns the exit status of the program.
 * **/
int main(void)
{
	char *full_command = NULL, *copy_command = NULL;
	size_t n = 0;
	ssize_t nchars_read; /* number of characters the user types */
	char **argv = NULL;
	int num_tokens;

	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "$ ", 2);
		/* get the string that the user types in and pass it to full_command */
		nchars_read = getline(&full_command, &n, stdin);
		/* check if the getline function failed or reached EOF or user use CTRL + D */
		if (nchars_read == -1)
		{
			free(full_command);
			return (-1);
		}
		else
		{
			/* let's allocate space to store the characters read by getline */
			copy_command = malloc(sizeof(char) * (nchars_read + 1));
			num_tokens = token_count(copy_command, full_command);
			execute(num_tokens, argv, copy_command, full_command);
			free(copy_command);
		}
	}
	return (0);
}
