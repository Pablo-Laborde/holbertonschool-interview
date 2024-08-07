#ifndef BINTREE_H
#define BINTREE_H


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
typedef struct binary_tree_s avl_t;


/* Functions */
	int binary_tree_is_avl(const binary_tree_t *tree);
	int avl_ch(const binary_tree_t *node);
	binary_tree_t *sv(binary_tree_t *node);
	binary_tree_t *sv(binary_tree_t *node);


#endif
