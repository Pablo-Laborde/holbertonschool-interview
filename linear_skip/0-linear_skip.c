#include "search.h"


/**
* linear_skip- func
* @list: skiplist_t *
* @value: int
* Return: skiplist_t *
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node = NULL, *prev = NULL;

	if (list)
	{
		prev = get_prev(list, value);
		node  = get_node(prev, value);
	}
	return (node);
}


/**
* get_prev- func
* @list: skiplist_t *
* @value: int
* Return: skiplist_t *
*/
skiplist_t *get_prev(skiplist_t *list, int value)
{
	skiplist_t *a1 = list, *a2 = NULL;

	if (a1)
	{
		printf("Value checked at index [%ld] = [%d]\n", a1->index, a1->n);
		if ((a1->express) && (a1->express->n < value))
			return (get_prev(a1->express, value));
		else
		{
			a2 = a1;
			if (a2->express)
				a2 = a2->express;
			else
				while (a2->next)
					a2 = a2->next;
			printf("Value found between indexes [%ld] and [%ld]\n"
					, a1->index, a2->index);
			return (a1);
		}
	}
	return (NULL);
}


/**
* get_node- func
* @list: skiplist_t *
* @value: int
* Return: skiplist_t *
*/
skiplist_t *get_node(skiplist_t *list, int value)
{
	skiplist_t *a1 = list;

	if (a1)
	{
		printf("Value checked at index [%ld] = [%d]\n", a1->index, a1->n);
		if (a1->n == value)
			return (a1);
		else
			return (get_node(a1->next, value));
	}
	return (a1);
}
