#include "main.h"
/**
* free_info - frees data structure
*
* @data_sh: data structure
* Return: Nothing
*/
void free_info(datashell *data_sh)
{
	unsigned int i;

	for (i = 0; data_sh->_envrn[i]; i++)
	{
		free(data_sh->_envrn[i]);
	}
	free(data_sh->_envrn);
	free(data_sh->p_id);
}

/**
* set_info - Initialize data structure
*
* @data_sh: data structure
* @argv: argument vector
* Return: no return
*/
void set_info(datashell *data_sh, char **argv)
{
	unsigned int j;

	data_sh->argv = argv;
	data_sh->input = NULL;
	data_sh->args = NULL;
	data_sh->status = 0;
	data_sh->count = 1;

	for (j = 0; environ[j]; j++)
		;
	data_sh->_envrn = malloc(sizeof(char *) * (j + 1));
	for (j = 0; environ[j]; j++)
	{
		data_sh->_envrn[j] = _strdup(environ[j]);
	}
	data_sh->_envrn[j] = NULL;
	data_sh->p_id = _itoa_(getpid());
}
/**
* main - Entry point
*
* @argc: argument count
* @argv: argument vector
*
* Return: 0 on success.
*/
int main(int argc, char **argv)
{
	datashell data_sh;
	(void) argc;

	signal(SIGINT, _get_sigint);
	set_info(&data_sh, argv);
	_shell_loop(&data_sh);
	free_info(&data_sh);
	if (data_sh.status < 0)
		return (255);
	return (data_sh.status);
}
