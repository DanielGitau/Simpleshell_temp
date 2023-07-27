#include "main.h"
/**
* num_repeated_char - counts the repetitions of a char
*
* @input: input string characters
* @index: index
* Return:number of repetitions
*/
int num_repeated_char(char *input, int index)
{
	if (*(input - 1) == *input)
		return (num_repeated_char(input - 1, index + 1));

	return (index);
}

/**
* error_syntx - finds syntax errors
*
* @input: input string character
* @index: position of char in string
* @last: last char read
* Return: index of error. 0 when there are no
* errors
*/
int error_syntx(char *input, int index, char last)
{
	int i;

	i = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_syntx(input + 1, index + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (index);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (index);

		if (last == '|')
		{
			i = num_repeated_char(input, 0);
			if (i == 0 || i > 1)
				return (index);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (index);

		if (last == '&')
		{
			i = num_repeated_char(input, 0);
			if (i == 0 || i > 1)
				return (index);
		}
	}

	return (error_syntx(input + 1, index + 1, *input));
}

/**
* indx_first_char - finds index of the first char
*
* @input: input string
* @index: position of char in string
* Return: 1 if there is an error. 0 in other case.
*/
int indx_first_char(char *input, int *index)
{

	for (*index = 0; input[*index]; *index += 1)
	{
		if (input[*index] == ' ' || input[*index] == '\t')
			continue;

		if (input[*index] == ';' || input[*index] == '|' || input[*index] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
* print_syntx_err - prints when a syntax error is found
*
* @data_sh: data structure
* @input: input string
* @i: index of the error
* @bool: to control msg error
* Return: no return
*/
void print_syntx_err(datashell *data_sh, char *input, int i, int bool)
{
	char *msg, *msg_2, *msg_3, *err, *count;
	int length;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg_2 = ": Syntax error: \"";
	msg_3 = "\" unexpected\n";
	count = _itoa_(data_sh->count);
	length = _strlen(data_sh->argv[0]) + _strlen(count);
	length += _strlen(msg) + _strlen(msg_2) + _strlen(msg_3) + 2;

	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(count);
		return;
	}
	_strcpy(err, data_sh->argv[0]);
	_strcat(err, ": ");
	_strcat(err, count);
	_strcat(err, msg_2);
	_strcat(err, msg);
	_strcat(err, msg_3);
	_strcat(err, "\0");

	write(STDERR_FILENO, err, length);
	free(err);
	free(count);
}

/**
* check_syntx_error - intermediate function to
* find and print a syntax error
*
* @data_sh: data structure
* @input: input string
* Return: 1 if there is an error. 0 in other case
*/
int check_syntx_error(datashell *data_sh, char *input)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = indx_first_char(input, &begin);
	if (f_char == -1)
	{
		print_syntx_err(data_sh, input, begin, 0);
		return (1);
	}

	i = error_syntx(input + begin, 0, *(input + begin));
	if (i != 0)
	{
		print_syntx_err(data_sh, input, begin + i, 1);
		return (1);
	}

	return (0);
}
