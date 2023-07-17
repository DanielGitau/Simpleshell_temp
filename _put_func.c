#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * put_s - outputs unformatted string
 * @str: a string to be outputted
 * Return: the num of char printed
 **/
int put_s(char *str)
{
	int i = 0, r_value = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		r_value++;
		i++;
	}

	return (r_value);
}
