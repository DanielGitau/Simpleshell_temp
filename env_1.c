#include "main.h"

/**
* _cmp_env_name - compares environment variables names
* with the input names.
* @n_env: name of the environment variable
* @name: the passed name
*
* Return: 0 if they are not equal. Another value if otherwise.
*/
int _cmp_env_name(const char *n_env, const char *name)
{
	int index;

	for (index = 0; n_env[index] != '='; index++)
	{
		if (n_env[index] != name[index])
		{
			return (0);
		}
	}

	return (index + 1);
}

/**
* _getenv - get an environment variable
* @name: name of the environment variable
* @_environ: environment variable
*
* Return: value of the environment variable if is found.
* otherwise returns NULL.
*/
char *_getenv(const char *name, char **_environ)
{
	char *env_pointr;
	int index, mov;

	/* Initialize ptr_env value */
	env_pointr = NULL;
	mov = 0;

	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (index = 0; _environ[index]; index++)
	{
		/* If name and env are equal */
		mov = _cmp_env_name(_environ[index], name);
		if (mov)
		{
			env_pointr = _environ[index];
			break;
		}
	}

	return (env_pointr + mov);
}

/**
* _env - prints the evironment variables
*
* @data_sh: data relevant.
* Return: 1 on success.
*/
int _env(datashell *data_sh)
{
	int i, j;

	for (i = 0; data_sh->_envrn[i]; i++)
	{

		for (j = 0; data_sh->_envrn[i][j]; j++)
			;

		write(STDOUT_FILENO, data_sh->_envrn[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	data_sh->status = 0;

	return (1);
}
