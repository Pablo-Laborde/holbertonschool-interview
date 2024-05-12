#ifndef SORT_H
#define SORT_H


/* Libraries */
	#include <stdio.h>


/* Functions */
	void print_array(const int *array, size_t size);

	void heap_sort(int *array, size_t size);
	void swap(int *array, size_t size, size_t p1, size_t p2);

	void sol_one(int *array, size_t size);

#endif
