#include "main.h"

/**
* _is_cdir - checks ":" if is in the current directory.
* @path: type char pointer char.
* @j: type int pointer of index.
* Return: 1 if the path is searchable in the cd, 0 otherwise.
*/
int _is_cdir(char *path, int *j)
{
	if (path[*j] == ':')
		return (1);

	while (path[*j] != ':' && path[*j])
	{
		*j += 1;
	}

	if (path[*j])
		*j += 1;

	return (0);
}

/**
* _which_ - locates a command
*
* @cmd: command name
* @_environ: environment variable
* Return: location of the command.
*/
char *_which_(char *cmd, char **_environ)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	path = _getenv("PATH", _environ);
	if (path)
	{
		ptr_path = _strdup(path);
		len_cmd = _strlen(cmd);
		token_path = _strtok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (_is_cdir(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy(dir, token_path);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
* _is_executable - determines if is an executable
*
* @data_sh: data structure
* Return: 0 if is not an executable, other number if it does
*/
int _is_executable(datashell *data_sh)
{
	struct stat st;
	int i;
	char *input;

	input = data_sh->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	_get_err(data_sh, 127);
	return (-1);
}

/**
* check_err_cmd - verifies if user has permissions to access
*
* @dir: destination directory
* @data_sh: data structure
* Return: 1 if there is an error, 0 if not
*/
int check_err_cmd(char *dir, datashell *data_sh)
{
	if (dir == NULL)
	{
		_get_err(data_sh, 127);
		return (1);
	}

	if (_strcmp(data_sh->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			_get_err(data_sh, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(data_sh->args[0], X_OK) == -1)
		{
			_get_err(data_sh, 126);
			return (1);
		}
	}

	return (0);
}

/**
* _cmd_exec - executes command lines
*
* @data_sh: data relevant (args and input)
* Return: 1 on success.
*/
int _cmd_exec(datashell *data_sh)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = _is_executable(data_sh);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which_(data_sh->args[0], data_sh->_envrn);
		if (check_err_cmd(dir, data_sh) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which_(data_sh->args[0], data_sh->_envrn);
		else
			dir = data_sh->args[0];
		execve(dir + exec, data_sh->args, data_sh->_envrn);
	}
	else if (pd < 0)
	{
		perror(data_sh->argv[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	data_sh->status = state / 256;
	return (1);
}
