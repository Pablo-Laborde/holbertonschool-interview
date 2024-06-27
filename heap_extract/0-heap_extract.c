/*Ex 0*/


#include "binary_trees.h"


/**
* heap_extract- func
* @root: heap_t **
* Return: int
*/
int heap_extract(heap_t **root)
{
	binary_tree_t *node = NULL, *ln = NULL, *an = NULL;
	int rv = 0;

	if (!root)
		return (0);
	node = *root;
	if (!node)
		return (0);
	rv = node->n;
	ln = gln(node);
	an = ln->parent;
	(an->right) ? (an->right = NULL) : (an->left = NULL);
	ln->parent = NULL;
	ln->right = node->right;
	ln->right->parent = ln;
	ln->left = node->left;
	ln->left->parent = ln;
	*root = ln;
	free(node);
	rbh(ln);
	return (rv);
}


/**
* gln- func
* @node: binary_tree_t *
* Return: binary_tree_t *
*/
binary_tree_t *gln(binary_tree_t *node)
{
	binary_tree_t *nn = NULL;

	if (!node->left && !node->right)
		return (node);
	else if (!node->left)
		nn = gln(node->right);
	else if (!node->right)
		nn = gln(node->left);
	else
		nn = (h(node->left) > h(node->right)) ?
			gln(node->left) : gln(node->right);
	return (nn);
}


/**
 * h - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
size_t h(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + h(tree->left) : 0;
	height_r = tree->right ? 1 + h(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}


/**
* rbh- func
* @node: binary_tree_t *
* Return: void
*/
void rbh(binary_tree_t *node)
{
	int a = 0;
	binary_tree_t *nn = NULL;

	if (node)
	{
		if (node->left && node->right)
			nn = (node->left->n > node->right->n) ? node->left : node->right;
		else if (node->left)
			nn = node->left;
		else if (node->right)
			nn = node->right;
		if (nn && (nn->n > node->n))
		{
			a = node->n;
			node->n = nn->n;
			nn->n = a;
			rbh(nn);
		}
	}
}
