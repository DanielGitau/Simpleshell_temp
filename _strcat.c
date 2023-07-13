#include "main.h"

/**
 * _strcat - Function to contatenate strings
 * @destination: Pointer to string
 * @source: Pointer to strings
 * Return: new concatenated string
 */
char *_strcat(char *destination, char *source)
{
	char *new = destination;

	while (*destination != '\0')
	{
		destination++;
	}

	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';

	return (new);
}
