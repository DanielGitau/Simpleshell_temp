#include "main.h"

/**
 * _memcpy - copies information between void pointers.
 * @newpointr: destination pointer.
 * @pointr: source pointer.
 * @len: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *newpointr, const void *pointr, unsigned int len)
{
	char *char_pointr = (char *)pointr;
	char *char_newpointr = (char *)newpointr;
	unsigned int index;

	for (index = 0; index < len; index++)
		char_newpointr[index] = char_pointr[index];
}

/**
 * _realloc - reallocates a memory block.
 * @pointr: pointer to the memory previously allocated.
 * @old_len: size, in bytes, of the allocated space of ptr.
 * @new_len: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new_len == old_len, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *pointr, unsigned int old_len, unsigned int new_len)
{
	void *newpointr;

	if (pointr == NULL)
		return (malloc(new_len));

	if (new_len == 0)
	{
		free(pointr);
		return (NULL);
	}

	if (new_len == old_len)
		return (pointr);

	newpointr = malloc(new_len);
	if (newpointr == NULL)
		return (NULL);

	if (new_len < old_len)
		_memcpy(newpointr, pointr, new_len);
	else
		_memcpy(newpointr, pointr, old_len);

	free(pointr);
	return (newpointr);
}

/**
 * _realloc_dp - reallocates a memory block of a double pointer.
 * @pointr: double pointer to the memory previously allocated.
 * @old_len: size, in bytes, of the allocated space of ptr.
 * @new_len: new size, in bytes, of the new memory block.
 *
 * Return: pointr.
 * if new_len == old_len, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_realloc_dp(char **pointr, unsigned int old_len, unsigned int new_len)
{
	char **newpointr;
	unsigned int index;

	if (pointr == NULL)
		return (malloc(sizeof(char *) * new_len));

	if (new_len == old_len)
		return (pointr);

	newpointr = malloc(sizeof(char *) * new_len);
	if (newpointr == NULL)
		return (NULL);

	for (index = 0; index < old_len; index++)
		newpointr[index] = pointr[index];

	free(pointr);

	return (newpointr);
}
