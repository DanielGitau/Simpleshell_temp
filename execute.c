#include "main.h"
void execute(int num_tokn, char **argv, char *copy_cmd, char *full_cmd)
{
	int counter, i;
	char *token, *delim = " \n";

	if (num_tokn != 0)
	{
		argv = malloc(sizeof(char *) * (num_tokn + 1));
		token = strtok(copy_cmd, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
			_strcpy(argv[i], token);

			/* printf(">>>>> %s \n", argv[i]);*/
			token = strtok(NULL, delim);
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
		{
			printf(">>>>> %s \n", argv[counter]);
			free(argv[counter]);
		}
		free(argv);
	}
}

