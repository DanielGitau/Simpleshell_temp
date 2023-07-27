#include "main.h"

/**
 * strcat_cd_er - function that concatenates the message for cd error
 *
 * @data_sh: data relevant (directory)
 * @mesg: message to print
 * @error: output error message
 * @ver_strn: counter lines
 * Return: error message
 */
char *strcat_cd_er(datashell *data_sh, char *mesg, char *error, char *ver_strn)
{
	char *ill_flag;

	_strcpy(error, data_sh->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_strn);
	_strcat(error, ": ");
	_strcat(error, data_sh->args[0]);
	_strcat(error, mesg);
	if (data_sh->args[1][0] == '-')
	{
		ill_flag = malloc(3);
		ill_flag[0] = '-';
		ill_flag[1] = data_sh->args[1][1];
		ill_flag[2] = '\0';
		_strcat(error, ill_flag);
		free(ill_flag);
	}
	else
	{
		_strcat(error, data_sh->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_msg_get_cd - error message for cd command in get_cd
 * @data_sh: data relevant (directory)
 * Return: Error message
 */
char *error_msg_get_cd(datashell *data_sh)
{
	int len, len_id;
	char *error, *ver_strn, *mesg;

	ver_strn = _itoa_(data_sh->count);
	if (data_sh->args[1][0] == '-')
	{
		mesg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		mesg = ": can't cd to ";
		len_id = _strlen(data_sh->args[1]);
	}

	len = _strlen(data_sh->argv[0]) + _strlen(data_sh->args[0]);
	len += _strlen(ver_strn) + _strlen(mesg) + len_id + 5;
	error = malloc(sizeof(char) * (len + 1));

	if (error == 0)
	{
		free(ver_strn);
		return (NULL);
	}

	error = strcat_cd_er(data_sh, mesg, error, ver_strn);

	free(ver_strn);

	return (error);
}

/**
 * error_cmd_not_found - generic error message for command not found
 * @data_sh: data relevant (counter, arguments)
 * Return: Error message
 */
char *error_cmd_not_found(datashell *data_sh)
{
	int len;
	char *error;
	char *ver_strn;

	ver_strn = _itoa_(data_sh->count);
	len = _strlen(data_sh->argv[0]) + _strlen(ver_strn);
	len += _strlen(data_sh->args[0]) + 16;
	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(error);
		free(ver_strn);
		return (NULL);
	}
	_strcpy(error, data_sh->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_strn);
	_strcat(error, ": ");
	_strcat(error, data_sh->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_strn);
	return (error);
}

/**
 * err_exit_shell - generic error message for exit in get_exit
 * @data_sh: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *err_exit_shell(datashell *data_sh)
{
	int len;
	char *error;
	char *ver_strn;

	ver_strn = _itoa_(data_sh->count);
	len = _strlen(data_sh->argv[0]) + _strlen(ver_strn);
	len += _strlen(data_sh->args[0]) + _strlen(data_sh->args[1]) + 23;
	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(ver_strn);
		return (NULL);
	}
	_strcpy(error, data_sh->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_strn);
	_strcat(error, ": ");
	_strcat(error, data_sh->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, data_sh->args[1]);
	_strcat(error, "\n\0");
	free(ver_strn);

	return (error);
}
