#include "binary_trees.h"


/**
* heap_insert- function
* @root: heap_t**
* @value: int
* Return: heap_t*
*/
heap_t *heap_insert(heap_t **root, int value)
{
	static int apos = 1; 
	heap_t *nn = NULL, *head = *root, *parent = NULL;

	if (root)
	{
		nn = create_node(value);
		if (nn)
		{
			if (head)
			{
				parent = pp(root, apos / 2);
				(apos % 2) ? parent->right = nn : parent->left = nn;
				sas(nn);
			}
			else
				*root = nn;
		}
	}
	return (nn);
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
* ss- function
* @beg: heap_t*
* Return: void
*/
void sas(heap_t *beg)
{
	heap_t *aux = beg->parent;
	int naux = 0;

	if (aux)
		if (beg->n < aux->n)
		{
			naux = beg->n;
			beg->n = aux->n;
			aux->n = naux;
			sas(aux);
		}
}


/**
* max_per_lvl- function
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
		}
	}
}


/**
* pp- function
* @root: head_t**
* @pos: int
* Return: head_t*
*/
head_t *pp(head_t **root, int pos)
{
	heap_t *aux = NULL;

	if (pos > 1)
		aux = pos_pointer(head, pos / 2);
	else
		return (*head);
	if (pos % 2)
		return (aux->right);
	else
		return (aux->left);
}
