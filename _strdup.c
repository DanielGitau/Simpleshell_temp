#include "main.h"

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
