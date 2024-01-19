#include "binary_trees.h"

/**
* binary_tree_node- function
* @parent: binary_tree_t*
* @value: int
* Return: binary_tree_t*
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nn = NULL;

	nn = malloc(sizeof(binary_tree_t));
	if (nn)
	{
		nn->n = value;
		nn->left = NULL;
		nn->right = NULL;
		nn->parent = parent;
		if (parent)
		{
			if (parent->n < value)
				parent->right = nn;
			else
				parent->left = nn;
		}
	}
	return (nn);
}
