#include "main.h"

/**
 * builtin_check - Checks if a command is a built-in command
 * @command: The command to be checked
 * Return: Returns true if the command is a built-in command, false otherwise
 */
bool builtin_check(const char *command)
{
	const char *built_ins[]  = {"exit", "env"};
	int i, size = sizeof(built_ins) / sizeof(built_ins[0]);

	for (i = 0; i < size; i++)
	{
		if (strcmp(command, built_ins[i]) == 0)
		{
			return (true);
		}
	}

	return (false);
}

/**
 * builtin_handler - Handles the execution of a built-in command
 * @argv: The array of command arguments.
 * @copy_cmd: A copy of the command string.
 * @full_cmd: The full command string.
 * @num_tokn: The number of tokens in the command
 */
void builtin_handler(char **argv, char *copy_cmd, char *full_cmd, int num_tokn)
{
	if (strcmp(argv[0], "env") == 0)
	{
		_env();
	}
	else if (strcmp(argv[0], "exit") == 0)
		exit_func(argv, copy_cmd, full_cmd, num_tokn);
}
