#include "binary_trees.h"


/**
* heap_insert- function
* @root: heap_t**
* @value: int
* Return: heap_t*
*/
heap_t *heap_insert(heap_t **root, int value)
{
	static int apos;
	heap_t *nn = NULL, *head = *root, *parent = NULL, *rr = NULL;

	if (root)
	{
		nn = create_node(value);
		if (nn)
		{
			apos++;
			if (head)
			{
				parent = pp(root, apos / 2);
				if (apos % 2)
					parent->right = nn;
				else
					parent->left = nn;
				nn->parent = parent;
			}
			else
				*root = nn;
			rr = sas(nn);
		}
	}
	return (rr);
}


/**
* create_node- function
* @value: int
* Return: heap_t*
*/
heap_t *create_node(int value)
{
	heap_t *nn = NULL;

	nn = malloc(sizeof(heap_t));
	if (nn)
	{
		nn->n = value;
		nn->left = NULL;
		nn->right = NULL;
		nn->parent = NULL;
	}
	return (nn);
}


/**
* sas- function
* @beg: heap_t*
* Return: void
*/
heap_t *sas(heap_t *beg)
{
	heap_t *aux = beg->parent;
	int naux = 0;

	if (aux)
		if (beg->n > aux->n)
		{
			naux = beg->n;
			beg->n = aux->n;
			aux->n = naux;
			return (sas(aux));
		}
	return (beg);
}


/**
* insert_in_pos- function
* @head: heap_t**
* @a: heap_t*
* @nn: heap_t*
* @pos: int
* Return: void
*/
void insert_in_pos(heap_t **head, heap_t *a, heap_t *nn, int pos)
{
	heap_t *b = NULL;

	if (a)
	{
		if (a->n < nn->n)
		{
			insert_in_pos(head, a->parent, nn, pos / 2);
		}
		else
		{
			if (!a)
				*head = nn;
			if (pos % 2)
			{
				b = a->right;
				a->right = nn;
			}
			else
			{
				b = a->left;
				a->left = nn;
			}
			(void)b;
		}
	}
}


/**
* pp- function
* @root: head_t**
* @pos: int
* Return: head_t*
*/
heap_t *pp(heap_t **root, int pos)
{
	heap_t *aux = NULL;

	if (pos > 1)
		aux = pp(root, pos / 2);
	else
		return (*root);
	if (pos % 2)
		return (aux->right);
	else
		return (aux->left);
}
