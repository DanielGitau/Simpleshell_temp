#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
/**
 * _getline - Read a line from a file stream and
 * dynamically allocate memory to store the line.
 *
 * @lineptr: A pointer to a pointer to a char. It will be updated to
 * point to the dynamically allocated buffer.
 * @n: A pointer to a size_t variable that holds size of the allocated buffer.
 * @stream: The file stream from which to read the line.
 * Return: The number of characters read, + the newline character ('\n').
 * Returns -1 if an error occurs or if the end of the file is reached.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    	size_t bufsize = *n;
	char *buffer = *lineptr;
	ssize_t bytes_read;
	size_t i = 0;
	
	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1); /* Invalid arguments */
	/* Check if the buffer is NULL or not large enough */
	if (buffer == NULL || bufsize < BUFFER_SIZE)
	{
        	bufsize = BUFFER_SIZE;
        	buffer = (char *)malloc(bufsize);
        	if (buffer == NULL)
			return (-1); /* Memory allocation failure */
	}
	while (i < bufsize - 1)
	{
        	/* Read bytes from the stream into the buffer using read syscall */
        	bytes_read = read(STDIN_FILENO, buffer + i, 1);
        	if (bytes_read <= 0)
			break; /* No more characters to read or error occurred */
		if (buffer[i] == '\n')
			break; /* Reached the end of the line */	
		i++;
	}
	buffer[i] = '\0'; /* Null-terminate the line */
	if (i == 0 && bytes_read == 0)
	{
		free(buffer); /* Free the buffer before returning */
		return (-1); /* No characters read (end-of-file reached) */
	}
	*lineptr = buffer;
	*n = bufsize;	
	return (i); /* Number of characters read (excluding null-terminator) */
}
