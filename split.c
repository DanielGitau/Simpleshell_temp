#include "main.h"

/**
* _swap_char - swaps | and & for non-printed chars
*
* @input: input string
* @bool: type of swap
* Return: swapped string
*/
char *_swap_char(char *input, int bool)
{
	int i;

	if (bool == 0)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				if (input[i + 1] != '|')
					input[i] = 16;
				else
					i++;
			}

			if (input[i] == '&')
			{
				if (input[i + 1] != '&')
					input[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			input[i] = (input[i] == 16 ? '|' : input[i]);
			input[i] = (input[i] == 12 ? '&' : input[i]);
		}
	}
	return (input);
}

/**
* _add_nodes - add separators and command lines in the lists
*
* @head_s: head of separator list
* @head_l: head of command lines list
* @input: input string
* Return: no return
*/
void _add_nodes(list_sep **head_s, list_line **head_l, char *input)
{
	int i;
	char *line;

	input = _swap_char(input, 0);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ';')
			add_sep_end(head_s, input[i]);

		if (input[i] == '|' || input[i] == '&')
		{
			add_sep_end(head_s, input[i]);
			i++;
		}
	}

	line = _strtok(input, ";|&");
	do {
		line = _swap_char(line, 1);
		add_line_end(head_l, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);

}

/**
* _go_next - go to the next command line stored
*
* @list_s: separator list
* @list_l: command line list
* @data_sh: data structure
* Return: no return
*/
void _go_next(list_sep **list_s, list_line **list_l, datashell *data_sh)
{
	int loop_sep;
	list_sep *ls_s;
	list_line *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (data_sh->status == 0)
		{
			if (ls_s->sep == '&' || ls_s->sep == ';')
				loop_sep = 0;
			if (ls_s->sep == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->sep == '|' || ls_s->sep == ';')
				loop_sep = 0;
			if (ls_s->sep == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
* _split_commands - splits command lines according to
* the separators ;, | and &, and executes them
*
* @data_sh: data structure
* @input: input string
* Return: 0 to exit, 1 to continue
*/
int _split_commands(datashell *data_sh, char *input)
{

	list_sep *head_s, *list_s;
	list_line *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	_add_nodes(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		data_sh->input = list_l->line;
		data_sh->args = _split_line(data_sh->input);
		loop = _exec_line(data_sh);
		free(data_sh->args);

		if (loop == 0)
			break;

		_go_next(&list_s, &list_l, data_sh);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_list_sep(&head_s);
	free_list_line(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
* _split_line - tokenizes the input string
*
* @input: input string.
* Return: string splitted.
*/
char **_split_line(char *input)
{
	size_t bsize;
	size_t i;
	char **tokens;
	char *token;

	bsize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, TOK_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokens = _realloc_dp(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}
