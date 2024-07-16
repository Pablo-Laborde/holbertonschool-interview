#include "list.h"


/**
* add_node_end- func
* @list: List **
* @str: char *
* Return: List *
*/
List *add_node_end(List **list, char *str)
{
	List *nn = NULL, *root = NULL;

	if (!list)
		return (NULL);
	nn = malloc(sizeof(List));
	if (!nn)
		return (NULL);
	nn->str = strdup(str);
	root = *list;
	if (root)
	{
		nn->next = root;
		nn->prev = root->prev;
		root->prev->next = nn;
		root->prev = nn;
	}
	else
	{
		nn->next = nn;
		nn->prev = nn;
		*list = nn;
	}
	return (nn);
}


/**
* add_node_begin- func
* @list: List **
* @str: char *
* Return: List *
*/
List *add_node_begin(List **list, char *str)
{
	List *nn = NULL;

	nn = add_node_end(list, str);
	*list = (*list)->prev;
	return (nn);
}
