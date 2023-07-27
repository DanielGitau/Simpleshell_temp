#include "main.h"

/**
 * add_sep_end - adds a separator found at the end
 * of a sep_list.
 * @head: head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the head.
 */
list_sep *add_sep_end(list_sep **head, char sep)
{
	list_sep *new_ptr, *temp;

	new_ptr = malloc(sizeof(list_sep));
	if (new_ptr == NULL)
		return (NULL);

	new_ptr->sep = sep;
	new_ptr->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new_ptr;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_ptr;
	}

	return (*head);
}

/**
 * free_list_sep - frees a sep_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_list_sep(list_sep **head)
{
	list_sep *temp;
	list_sep *curr_ptr;

	if (head != NULL)
	{
		curr_ptr = *head;
		while ((temp = curr_ptr) != NULL)
		{
			curr_ptr = curr_ptr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_end - adds a command line at the end
 * of a line_list.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
list_line *add_line_end(list_line **head, char *line)
{
	list_line *new_list, *temp;

	new_list = malloc(sizeof(list_line));
	if (new_list == NULL)
		return (NULL);

	new_list->line = line;
	new_list->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new_list;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_list;
	}

	return (*head);
}

/**
 * free_list_line - frees a line_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_list_line(list_line **head)
{
	list_line *temp;
	list_line *curr_list;

	if (head != NULL)
	{
		curr_list = *head;
		while ((temp = curr_list) != NULL)
		{
			curr_list = curr_list->next;
			free(temp);
		}
		*head = NULL;
	}
}
