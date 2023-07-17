#include "main.h"
/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte, to the
 * buffer pointed to by dest.
 * @dest: destination.
 * @src: source.
 * Return: the pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) != '\0')
			count++;
		else
			count = -1;
	}
	return (dest);
}

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

char* _strdup(char* str)
{
	size_t len = _strlen(str) + 1;  /* Get the length of the string, including the null byte*/
	char* dup = malloc(len);  /* Allocate memory for the duplicated string*/
	if (dup != NULL)
	{
        	_strcpy(dup, str);  /* Copy the string to the allocated memory */
	}
    return (dup);
}
/**
 * _strlen - returns the length of a string
 * @s: input string
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i))
		i++;
	return (i);
}
