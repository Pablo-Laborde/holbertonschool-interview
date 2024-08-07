#include "binary_trees.h"


/**
* binary_tree_is_avl- func
* @tree: binary_tree_t
* Return: int
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (avl_ch(tree) < 1)
		return (0);
	if (!sv(tree))
		return (0);
	return (1);
}


/**
* avl_ch- func
* @node: binary_tree_t *
* Return: int
*/
int avl_ch(const binary_tree_t *node)
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


/**
* sv- func
* @node: binary_tree_t *
* Return: binary_tree_t *
*/
binary_tree_t *sv(const binary_tree_t *node)
{
	binary_tree_t *rn = NULL, *ln = NULL, *nn = node;

	if (!nn->right && !nn->left)
		return (nn);
	if (!nn->right)
		return (sv(nn->left));
	if (!nn->left)
		return (sv(nn->right));
	rn = sv(nn->right);
	if (!rn || (rn->n < nn->n))
		return (NULL);
	return (sv(nn->left));
}
