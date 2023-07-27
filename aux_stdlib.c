#include "main.h"

/**
 * get_length - Get the lenght of a number.
 * @n: type int number.
 * Return: Lenght of a number.
 */
int get_length(int n)
{
	unsigned int n1;
	int lengh = 1;

	if (n < 0)
	{
		lengh++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		lengh++;
		n1 = n1 / 10;
	}

	return (lengh);
}
/**
 * _itoa_ - function converts int to string.
 * @n: type int number
 * Return: String.
 */
char *_itoa_(int n)
{
	unsigned int n1;
	int lenght = get_length(n);
	char *buff;

	buff = malloc(sizeof(char) * (lenght + 1));
	if (buff == 0)
		return (NULL);

	*(buff + lenght) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buff[0] = '-';
	}
	else
	{
		n1 = n;
	}

	lenght--;
	do {
		*(buff + lenght) = (n1 % 10) + '0';
		n1 = n1 / 10;
		lenght--;
	}
	while (n1 > 0)
		;
	return (buff);
}

/**
 * _atoi_ - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi_(char *s)
{
	unsigned int counter = 0, size = 0, oin = 0, pn = 1, m = 1, i;

	while (*(s + counter) != '\0')
	{
		if (size > 0 && (*(s + counter) < '0' || *(s + counter) > '9'))
			break;

		if (*(s + counter) == '-')
			pn *= -1;

		if ((*(s + counter) >= '0') && (*(s + counter) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		counter++;
	}

	for (i = counter - size; i < counter; i++)
	{
		oin = oin + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oin * pn);
}
