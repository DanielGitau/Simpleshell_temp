#include "main.h"

/**
* _check_env - checks if the typed variable is an env variable
*
* @h: head of linked list
* @in: input string
* @data: data structure
* Return: no return
*/
void _check_env(var_li **h, char *in, datashell *data)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = data->_envrn;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = _strlen(_envr[row] + chr + 1);
				_add_rvar_node_end(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	_add_rvar_node_end(h, j, NULL, 0);
}

/**
* _check_vars - check if the typed variable is $$ or $?
*
* @h: head of the linked list
* @in: input string
* @st: last status of the Shell
* @data: data structure
* Return: no return
*/
int _check_vars(var_li **h, char *in, char *st, datashell *data)
{
	int i, lst, lpd;

	lst = _strlen(st);
	lpd = _strlen(data->p_id);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				_add_rvar_node_end(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				_add_rvar_node_end(h, 2, data->p_id, lpd), i++;
			else if (in[i + 1] == '\n')
				_add_rvar_node_end(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				_add_rvar_node_end(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				_add_rvar_node_end(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				_add_rvar_node_end(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				_add_rvar_node_end(h, 0, NULL, 0);
			else
				_check_env(h, in + i, data);
		}
	}

	return (i);
}

/**
* _replaced_input - replaces string into variables
*
* @head: head of the linked list
* @input: input string
* @new_input: new input string (replaced)
* @nlen: new length
* Return: replaced string
*/
char *_replaced_input(var_li **head, char *input, char *new_input, int nlen)
{
	var_li *indx;
	int i, j, k;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (k = 0; k < indx->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					new_input[i] = indx->val[k];
					i++;
				}
				j += (indx->len_var);
				i--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
* _replace_var - calls functions to replace string into vars
*
* @input: input string
* @data_sh: data structure
* Return: replaced string
*/
char *_replace_var(char *input, datashell *data_sh)
{
	var_li *head, *indx;
	char *status, *new_input;
	int olen, nlen;

	status = _itoa_(data_sh->status);
	head = NULL;

	olen = _check_vars(&head, input, status, data_sh);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = _replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_var_li(&head);

	return (new_input);
}
