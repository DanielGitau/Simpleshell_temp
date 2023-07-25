#include "main.h"
/**
 * execute - Executes a command with the provided arguments.
 * The function performs the execution of the command,
 * by calling appropriate function,
 * based on the command type, such as built-in commands or external programs.
 * It handles the execution flow and any necessary error handling.
 * @num_tokn: The number of tokens in the command.
 * @argv: The array of command arguments.
 * @copy_cmd: A copy of the command string.
 * @full_cmd: The full command string.
 * **/
void execute(int num_tokn, char **argv, char *copy_cmd, char *full_cmd)
{
	int counter, i;
	char *token, *delim = " \n";

	if (num_tokn != 0)
	{
		argv = malloc(sizeof(char *) * (num_tokn + 1));
		token = _strtok(copy_cmd, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
			_strcpy(argv[i], token);
			token = _strtok(NULL, delim);
		}
		argv[i] = NULL;

		/*check for built_in */
		if (builtin_check(argv[0]))
			builtin_handler(argv, copy_cmd, full_cmd, num_tokn);
		/* execute the commands with execve */
		else
			execmd(argv);
		/* free print the content of argv */
		for (counter = 0; counter < num_tokn; counter++)
			free(argv[counter]);
		free(argv);
	}
}
