#include "main.h"
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

void builtin_handler(char **argv, char *copy_command, char *full_command, int num_tokens)
{
	if (strcmp(argv[0], "env") == 0)
	{
		_env();
	}
	else if (strcmp(argv[0], "exit") == 0)
		exit_func(argv, copy_command, full_command, num_tokens);
}
