#include "sort.h"


/**
* radix_sort- func
* @array: int *
* @size: size_t
* Return: void
*/
void radix_sort(int *array, size_t size)
{
	size_t pos = 0, i = 1;
	int lvl = 1, key = 0, sorted = 0;
	ht **root = NULL;

	if (size > 1)
	{
		root = create_hash();
		while (!sorted)
		{
			for (pos = 0; pos < size; pos++)
			{
				key = key_maker(array[pos], lvl);
				add_elem(root, array[pos], key);
			}
			lvl++;
			hash_to_array(root, array);
			print_array(array, size);
			sorted = 1;
			for (i = 1; sorted && (i < size); i++)
				if (array[i - 1] > array[i])
					sorted = 0;
		}
		free(root);
	}
}


/**
* key_maker- func
* @n: int
* @lvl: int
* Return: int
*/
int key_maker(int n, int lvl)
{
	int i = 1, num = 1;

	for (; i < lvl; i++)
		num *= 10;
	return ((n / num) % 10);
}


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
* hash_to_array- func
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
