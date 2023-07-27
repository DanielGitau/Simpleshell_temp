#include "main.h"

/**
* _get_builtin - builtin that pais the command in the arg
* @cmd: command
* Return: function pointer of the builtin command
*/
int (*_get_builtin(char *cmd))(datashell *)
{
	_builtin builtin[] = {
		{ "env", _env },
		{ "exit", _exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", _cd_shell },
		{ "help", _get_help },
		{ NULL, NULL }
	};
	int index;

	for (index = 0; builtin[index].name; index++)
	{
		if (_strcmp(builtin[index].name, cmd) == 0)
			break;
	}

	return (builtin[index].f);
}
