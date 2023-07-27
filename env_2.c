#include "main.h"

/**
* copy_data - copies info to create
* a new env or alias
* @name: name (env or alias)
* @value: value (env or alias)
*
* Return: new env or alias.
*/
char *copy_data(char *name, char *value)
{
	char *new_env;
	int len_name, len_val, length;

	len_name = _strlen(name);
	len_val = _strlen(value);
	length = len_name + len_val + 2;
	new_env = malloc(sizeof(char) * (length));
	_strcpy(new_env, name);
	_strcat(new_env, "=");
	_strcat(new_env, value);
	_strcat(new_env, "\0");

	return (new_env);
}

/**
* _set_env - sets an environment variable
*
* @name: name of the environment variable
* @value: value of the environment variable
* @data_sh: data structure (environ)
* Return: no return
*/
void _set_env(char *name, char *value, datashell *data_sh)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; data_sh->_envrn[i]; i++)
	{
		var_env = _strdup(data_sh->_envrn[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(data_sh->_envrn[i]);
			data_sh->_envrn[i] = copy_data(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	data_sh->_envrn = _realloc_dp(data_sh->_envrn, i, sizeof(char *) * (i + 2));
	data_sh->_envrn[i] = copy_data(name, value);
	data_sh->_envrn[i + 1] = NULL;
}

/**
* _setenv - compares env variables names
* with the name passed.
* @data_sh: data relevant (env name and env value)
*
* Return: 1 on success.
*/
int _setenv(datashell *data_sh)
{

	if (data_sh->args[1] == NULL || data_sh->args[2] == NULL)
	{
		_get_err(data_sh, -1);
		return (1);
	}

	_set_env(data_sh->args[1], data_sh->args[2], data_sh);

	return (1);
}

/**
* _unsetenv - deletes a environment variable
*
* @data_sh: data relevant (env name)
*
* Return: 1 on success.
*/
int _unsetenv(datashell *data_sh)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (data_sh->args[1] == NULL)
	{
		_get_err(data_sh, -1);
		return (1);
	}
	k = -1;
	for (i = 0; data_sh->_envrn[i]; i++)
	{
		var_env = _strdup(data_sh->_envrn[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, data_sh->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		_get_err(data_sh, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; data_sh->_envrn[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = data_sh->_envrn[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(data_sh->_envrn[k]);
	free(data_sh->_envrn);
	data_sh->_envrn = realloc_environ;
	return (1);
}
