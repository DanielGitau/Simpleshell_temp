#include "main.h"
/**
 * find_beginning_of_token - Function to find the
 * beginning of the next token
 *
 * @token: Pointer to the current position in the string
 * @delim: The set of delimiter characters
 * Return: A pointer to the beginning of the next token
 */
char *find_beginning_of_token(char *token, const char *delim)
{
	const char *d;
	int is_delim;

	while (*token)
	{
		is_delim = 0;
		d = delim;
		
		while (*d)
		{
			if (*token == *d)
			{
				is_delim = 1;
				break;
			}
			d++;
		}
		
		if (!is_delim)
			break;
		token++;
	}
	return (token);
}

/**
 * find_end_of_token - Function to find the end of the current token
 * @next_token: Pointer to the character after the current token
 * @delim: The set of delimiter characters
 * Return: A pointer to the next token, or NULL if no more tokens are found
 */
char *find_end_of_token(char *next_token, const char *delim)
{
	int is_delim;
	const char *d;
	
	while (*next_token)
	{
		is_delim = 0;
		d = delim;
		
		while (*d)
		{
			if (*next_token == *d)
			{
				is_delim = 1;
				break;
			}
			d++;
		}
		if (is_delim)
			break;
		next_token++;
	}
	return (next_token);
}

/**
 * custom_strtok - Function to tokenize a string
 * based on a set of delimiter characters
 *
 * @str: The string to be tokenized
 * @delim: The set of delimiter characters
 * Return: A pointer to the next token,
 * or NULL if no more tokens are found
 */
char *_strtok(char *str, const char *delim)
{
	static char *token_ptr;
	static char *next_token;
	char *token;
	
	if (str != NULL)
		token_ptr = str;
	if (token_ptr == NULL)
		return (NULL);
	
	token = token_ptr;
	token = find_beginning_of_token(token, delim);
	if (*token == '\0')
	{
		token_ptr = NULL;
		return (NULL);
	}
	
	next_token = token + 1;
	next_token = find_end_of_token(next_token, delim);
	if (*next_token == '\0')
		token_ptr = NULL;
	else
	{
		*next_token = '\0';
		token_ptr = next_token + 1;
	}
	return (token);
}
