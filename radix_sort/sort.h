#ifndef SORT_H
#define SORT_H


#include <stdlib.h>
#include <stdio.h>



/**
* struct- ht_s
* @nd: ht_s *
* @nn: ht_s *
* @d: int
*/
struct ht_s
{
	struct ht_s *next;
	int n;
};

typedef struct ht_s ht;


/* Functions */
	void print_array(const int *array, size_t size);

	void radix_sort(int *array, size_t size);
	int key_maker(int n, int lvl);
	ht **create_hash();
	void add_elem(ht **root, int n, int key);
	void hash_to_array(ht **root, int *array);


#endif
