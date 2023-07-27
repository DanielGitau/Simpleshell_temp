#include "main.h"

/**
* _get_help - function that retrieves help messages according builtin
* @data_sh: data structure (args and input)
* Return: Return 0
*/
int _get_help(datashell *data_sh)
{

	if (data_sh->args[1] == 0)
		aux_help_general_info();
	else if (_strcmp(data_sh->args[1], "setenv") == 0)
		aux_help_setenv_info();
	else if (_strcmp(data_sh->args[1], "env") == 0)
		aux_help_env_info();
	else if (_strcmp(data_sh->args[1], "unsetenv") == 0)
		aux_help_unsetenv_info();
	else if (_strcmp(data_sh->args[1], "help") == 0)
		aux_help_info();
	else if (_strcmp(data_sh->args[1], "exit") == 0)
		aux_help_exit_info();
	else if (_strcmp(data_sh->args[1], "cd") == 0)
		aux_help_cd_info();
	else if (_strcmp(data_sh->args[1], "alias") == 0)
		aux_help_alias_info();
	else
		write(STDERR_FILENO, data_sh->args[0],
			_strlen(data_sh->args[0]));

	data_sh->status = 0;
	return (1);
}
