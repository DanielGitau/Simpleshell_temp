#include "main.h"
#define BUFFER_SIZE 1024

char *custom_getline()
{
	static char buffer[BUFFER_SIZE];
	static int pos;
	static int length;

	if (pos >= length)
	{
		length = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (length <= 0)
		{
			return (NULL); /* End of input or error */
		}
		pos = 0;
	}

	char *line = NULL;
	int line_length = 0;

	while (pos < length && buffer[pos] != '\n')
	{
		line = realloc(line, line_length + 1);
		line[line_length++] = buffer[pos++];
	}

	if (pos < length && buffer[pos] == '\n')
	{
		pos++; /* Move past the newline character */
	}

	if (line != NULL)
	{
		line = realloc(line, line_length + 1);
		line[line_length] = '\0';
	}

	return (line);
}
