#include "main.h"
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>

ssize_t custom_getline(char **line, size_t *len, FILE *file)
{
	/* size_t buffer_size = 0; */
	ssize_t characters_read = 0;
	int c;
	char *temp = (char *)realloc(*line, *len);

	if (!line || !len || !file)
	{
		return (-1); /* Invalid input parameters */
	}

	/* Check if line is NULL or buffer size is 0, and allocate initial memory */
	if (*line == NULL || *len == 0)
	{
		*len = 128; /* Initial buffer size */
		*line = (char *)malloc(*len);
		if (*line == NULL)
		{
			return (-1); /* Memory allocation failed */
		}
	}

	while ((c = fgetc(file)) != EOF)
	{
		if (characters_read >= (ssize_t)(*len) - 1)
		{
			/* Expand the buffer if needed */
			*len *= 2; /* Double the buffer size */

			if (temp == NULL)
			{
				return (-1); /* Memory reallocation failed */
			}
			*line = temp;
		}

		(*line)[characters_read] = c;
		characters_read++;

		if (c == '\n')
		{
			break; /* End of line reached */
		}
	}

	if (characters_read == 0)
	{
		return (-1); /* No characters read (e.g., end of file) */
	}

	(*line)[characters_read] = '\0'; /* Null-terminate the line */
	return (characters_read);
}
