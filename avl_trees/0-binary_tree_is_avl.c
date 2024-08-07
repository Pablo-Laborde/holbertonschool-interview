#include "binary_trees.h"


/**
* binary_tree_is_avl- func
* @tree: binary_tree_t
* Return: int
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int rv = 0;

	if (tree)
		rv = avl_ch(tree);
	if (rv == -1)
		return (0);
	return (rv);
}


/**
* avl_ch- func
* @node: binary_tree_t *
* Return: int
*/
int avl_ch(binary_tree_t *node)
{
	int lh = 0, rh = 0, dif = 0;
	
	if (!node)
		return (0);
	lh = avl_ch(node->left);
	rh = avl_ch(node->right);
	if ((rh == -1) || (lh == -1))
		return (-1);
	if (lh && (node->left->n > node->n))
		return (-1);
	if (rh && (node->right->n < node->n))
		return (-1);
	dif = rh - lh;
	if ((dif > -2) && (dif < 2))
		return (((rh > lh) ? (rh + 1) : (lh + 1)));
	return (-1);
}
