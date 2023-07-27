#include "main.h"

/**
* _cd_shell - changes current directory
*
* @data_sh: data relevant
* Return: 1 on success
*/
int _cd_shell(datashell *data_sh)
{
	char *dir;
	int ishome, is_home, is_dash;

	dir = data_sh->args[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		is_home = _strcmp("~", dir);
		is_dash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !is_home || !is_dash)
	{
		cd_to_home_dir(data_sh);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_prev_dir(data_sh);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_paren(data_sh);
		return (1);
	}

	cd_given(data_sh);

	return (1);
}
