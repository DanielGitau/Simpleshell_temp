#include "main.h"

/**
 * _strdup - duplicates a str in the memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - Returns the lenght of a str.
 * @s: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_char_len - compare chars of strings
 * @arr: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_char_len(char arr[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; arr[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (arr[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string by some delimiter.
 * @arr: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char arr[], const char *delim)
{
	static char *tokn, *tokn_end;
	char *tokn_start;
	unsigned int i, bool;

	if (arr != NULL)
	{
		if (cmp_char_len(arr, delim))
			return (NULL);
		tokn = arr; /*Store first address*/
		i = _strlen(arr);
		tokn_end = &arr[i]; /*Store last address*/
	}
	tokn_start = tokn;
	if (tokn_start == tokn_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *tokn; tokn++)
	{
		/*Breaking loop finding the next token*/
		if (tokn != tokn_start)
			if (*tokn && *(tokn - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*tokn == delim[i])
			{
				*tokn = '\0';
				if (tokn == tokn_start)
					tokn_start++;
				break;
			}
		}
		if (bool == 0 && *tokn) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (tokn_start);
}

/**
 * _isdigit - check if arg passed is digit
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
