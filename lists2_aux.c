#include "main.h"

/**
 * _add_rvar_node_end - adds a variable at the end
 * of a r_var list.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head.
 */
var_li *_add_rvar_node_end(var_li **head, int lvar, char *val, int lval)
{
	var_li *new_var, *temp;

	new_var = malloc(sizeof(var_li));
	if (new_var == NULL)
		return (NULL);

	new_var->len_var = lvar;
	new_var->val = val;
	new_var->len_val = lval;

	new_var->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new_var;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_var;
	}

	return (*head);
}
/**
 * free_var_li - frees a r_var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_var_li(var_li **head)
{
	var_li *temp;
	var_li *curr_var;

	if (head != NULL)
	{
		curr_var = *head;
		while ((temp = curr_var) != NULL)
		{
			curr_var = curr_var->next;
			free(temp);
		}
		*head = NULL;
	}
}
