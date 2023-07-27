#include "main.h"

/**
* _exit_shell - exits the shell
*
* @data_sh: data relevant (status and args)
* Return: 0 on success.
*/
int _exit_shell(datashell *data_sh)
{
	unsigned int ustatus;
	int is_digit;
	int len;
	int number;

	if (data_sh->args[1] != NULL)
	{
		ustatus = _atoi_(data_sh->args[1]);
		is_digit = _isdigit(data_sh->args[1]);
		len = _strlen(data_sh->args[1]);
		number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || len > 10 || number)
		{
			_get_err(data_sh, 2);
			data_sh->status = 2;
			return (1);
		}

		data_sh->status = (ustatus % 256);
	}
	return (0);
}
