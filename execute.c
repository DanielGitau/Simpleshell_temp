#include "main.h"
void execute(int num_tokens, char **argv, char *copy_command)
{
	int counter, i;
	char *token, *delim = " \n";

       	if (num_tokens != 0)
	{
		argv = malloc(sizeof(char *) * (num_tokens + 1));
		token = strtok(copy_command, delim);
		
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
			_strcpy(argv[i], token);
			
			/* printf(">>>>> %s \n", argv[i]);*/
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		/* execute the commands with execve */
		execmd(argv);
		
		/* print the content of argv */
		for (counter = 0; counter<num_tokens; counter++)
		{
			printf(">>>>> %s \n", argv[counter]);
			free(argv[counter]);
		}
		free(argv);
	}
}

