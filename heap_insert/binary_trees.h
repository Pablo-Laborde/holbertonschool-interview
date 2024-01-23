#ifndef BT_H
#define BT_H

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


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);


void binary_tree_print(const binary_tree_t *tree);


heap_t *heap_insert(heap_t **root, int value);


heap_t *create_node(int value);


void sas(heap_t *beg);


void insert_in_pos(heap_t **head, heap_t *a, heap_t *nn, int pos);


heap_t *pp(heap_t **root, int pos);


#endif
