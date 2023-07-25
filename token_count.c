#include "main.h"

/**
 * token_count - Function counts the number of tokens in a given command
 * @copy_command: Pointer to an array used to store a copy of the original
 * @full_command: Pointer to an array with the command to be tokenized
 * Return: The number of tokens
 */
int token_count(char *copy_command, char *full_command)
{
	const char *delim = " \n";
	char *token;
	int num_tokens;

	/* make a copy of the command that was typed */
	_strcpy(copy_command, full_command);

	/* split the string (full_command) into an array of words */
	token = _strtok(full_command, delim);

	/*
	 * allocate space to store the variable arguments but
	 * before then determine how many tokens are there
	 */
	num_tokens = 0;
	while (token != NULL)
	{
		num_tokens++;
		token = _strtok(NULL, delim);
	}
	return (num_tokens);
}
