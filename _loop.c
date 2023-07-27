#include "main.h"

/**
* _without_comment - deletes comments from the input
*
* @input: input string
* Return: input without comments
*/
char *_without_comment(char *input)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '#')
		{
			if (i == 0)
			{
				free(input);
				return (NULL);
			}
			if (input[i - 1] == ' ' || input[i - 1] == '\t' ||
				input[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		input = _realloc(input, i, up_to + 1);
		input[up_to] = '\0';
	}

	return (input);
}

/**
* _shell_loop - Loop of shell
* @data_sh: data relevant (av, input, args)
*
* Return: no return.
*/
void _shell_loop(datashell *data_sh)
{
	int loop, i_eof;
	char *in;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		in = _read_line(&i_eof);
		if (i_eof != -1)
		{
			in = _without_comment(in);
			if (in == NULL)
				continue;
			if (check_syntx_error(data_sh, in) == 1)
			{
				data_sh->status = 2;
				free(in);
				continue;
			}
			in = _replace_var(in, data_sh);
			loop = _split_commands(data_sh, in);
			data_sh->count += 1;
			free(in);
		}
		else
		{
			loop = 0;
			free(in);
		}
	}
}
