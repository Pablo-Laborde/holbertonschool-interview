#ifndef BIN_TREE_H
#define BIN_TREE_H


#include <stdio.h>
#include <stdlib.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;


/* Functions */
	int heap_extract(heap_t **root);
	binary_tree_t *gln(binary_tree_t *node);
	void rbh(binary_tree_t *node);
	size_t h(const binary_tree_t *tree);

#endif
