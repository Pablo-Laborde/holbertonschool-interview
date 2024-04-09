#include "binary_trees.h"


/**
* sorted_array_to_avl- func
* @array: int *
* @size: size_t
* Return: avl_t *
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array)
		return (NULL);
	root = make_avl(array, NULL, 0, size - 1);
	return (root);
}


/**
* make_avl- func
* @array: int *
* @parent: avl_t *
* @b: size_t
* @e: size_t
* Return: avl_t *
*/
avl_t *make_avl(int *array, avl_t *parent, size_t b, size_t e)
{
	size_t mid = 0;
	avl_t *node = NULL;

	if (e < b)
		return (NULL);
	mid = ((e - b) % 2) ? ((e - b) / 2 + 1) : ((e - b) / 2);
	mid += b;
	node = malloc(sizeof(avl_t));
	if (!node)
		exit(1);
	node->n = array[mid];
	node->parent = parent;
	if (b == e)
	{
		node->left = NULL;
		node->right = NULL;
	}
	else
	{
		node->left = make_avl(array, node, b, mid - 1);
		node->right = make_avl(array, node, mid + 1, e);
	}
	return (node);
}
