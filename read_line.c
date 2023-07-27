#include "main.h"

/**
 * _read_line - reads the input string.
 *
 * @line_value: return value of getline function
 * Return: input string
 */
char *_read_line(int *line_value)
{
	char *input = NULL;
	size_t bufsize = 0;

	*line_value = getline(&input, &bufsize, stdin);

	return (input);
}
