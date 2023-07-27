#include "main.h"

/**
 * _exec_line - finds builtins and commands
 *
 * @data_sh: data relevant (args)
 * Return: 1 on success.
 */
int _exec_line(datashell *data_sh)
{
	int (*builtin)(datashell *data_sh);

	if (data_sh->args[0] == NULL)
		return (1);

	builtin = _get_builtin(data_sh->args[0]);

	if (builtin != NULL)
		return (builtin(data_sh));

	return (_cmd_exec(data_sh));
}
