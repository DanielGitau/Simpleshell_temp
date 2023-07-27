#include "main.h"

/**
 * error_msg_env - error message for env in get_env.
 * @data_sh: data relevant (counter, arguments)
 * Return: error message.
 */
char *error_msg_env(datashell *data_sh)
{
	int len;
	char *error;
	char *ver_strn;
	char *mesg;

	ver_strn = _itoa_(data_sh->count);
	mesg = ": Unable to add/remove from environment\n";
	len = _strlen(data_sh->argv[0]) + _strlen(ver_strn);
	len += _strlen(data_sh->args[0]) + _strlen(mesg) + 4;
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
	_strcat(error, mesg);
	_strcat(error, "\0");
	free(ver_strn);

	return (error);
}
/**
 * error_msg_path - error message for path and failure denied permission.
 * @data_sh: data relevant (counter, arguments).
 *
 * Return: The error string.
 */
char *error_msg_path(datashell *data_sh)
{
	int len;
	char *ver_strn;
	char *error;

	ver_strn = _itoa_(data_sh->count);
	len = _strlen(data_sh->argv[0]) + _strlen(ver_strn);
	len += _strlen(data_sh->args[0]) + 24;
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
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_strn);
	return (error);
}
