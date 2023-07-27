#include "main.h"

/**
* _get_err - calls the error according the builtin, syntax or permission
* @data_sh: data structure that contains arguments
* @err_val: error value
* Return: error
*/
int _get_err(datashell *data_sh, int err_val)
{
	char *err;

	switch (err_val)
	{
		case -1:
			err = error_msg_env(data_sh);
			break;
		case 126:
			err = error_msg_path(data_sh);
			break;
		case 127:
			err = error_cmd_not_found(data_sh);
			break;
		case 2:
			if (_strcmp("exit", data_sh->args[0]) == 0)
				err = err_exit_shell(data_sh);
			else if (_strcmp("cd", data_sh->args[0]) == 0)
				err = error_msg_get_cd(data_sh);
			break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}

	data_sh->status = err_val;
	return (err_val);
}
