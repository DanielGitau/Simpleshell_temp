#include "main.h"

int token_count (char *copy_command, char *full_command)
{
	const char *delim = " \n";
	char *token;
	int num_tokens;

	/* make a copy of the command that was typed */
	_strcpy(copy_command, full_command);
	
	/* split the string (full_command) into an array of words */
	token = strtok(full_command, delim);
	
	/* allocate space to store the variable arguments but before then determine how many tokens are there*/
	num_tokens = 0;
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	printf(">>>>> num_of_token(s) %d \n", num_tokens);

	return (num_tokens);
}
