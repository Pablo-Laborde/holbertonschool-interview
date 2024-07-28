#include "sort.h"


/**
* create_hash- func
* Return: ht **
*/
ht **create_hash()
{
	int i = 0;
	ht **root = NULL;

	root = malloc(sizeof(ht *) * 10);
	if (!root)
		exit(1);
	for (; i < 10; i++)
		root[i] = NULL;
	return (root);
}


/**
* add_elem- func
* @root: ht **
* @n: int
* @key: int
* Return: void
*/
void add_elem(ht **root, int n, int key)
{
	ht *node = NULL, *pos = NULL;

	node = malloc(sizeof(ht));
	if (!node)
		exit(1);
	node->next = NULL;
	node->n = n;
	pos = root[key];
	if (pos)
	{
		while (pos->next)
			pos = pos->next;
		pos->next = node;
	}
	else
		root[key] = node;
}


/**
* pop_elem- func
* @root: ht **
* @array: int *
* Return: void
*/
void hash_to_array(ht **root, int *array)
{
	int pos = 0, i = 0;
	ht *elem = NULL, *aux = NULL;

	for (; i < 10; i++)
	{
		elem = root[i];
		while (elem)
		{
			array[pos] = elem->n;
			aux = elem;
			elem = elem->next;
			pos++;
			free(aux);
		}
		root[i] = NULL;
	}
}


/**
* print_hash- func
* @root: ht **
* Return: void
*/
void print_hash(ht **root)
{
	int i = 0;
	ht *elem = NULL;

	for (; i < 10; i++)
	{
		elem = root[i];
		while (elem)
		{
			printf("%d, ", elem->n);
			elem = elem->next;
		}
	}
	printf("\n");
}
