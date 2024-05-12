#include "sort.h"


/**
* heap_sort- func
* @array: int *
* @size: size_t
* Return: void
*/
void heap_sort(int *array, size_t size)
{
	sol_one(array, size);
}


/**
* swap- func
* @array: int *
* @size: size_t
* @end: size_t
* @beg: size_t
* Return: void
*/
void swap(int *array, size_t size, size_t end, size_t beg)
{
	int a = 0;

	a = array[end];
	array[end] = array[beg];
	array[beg] = a;
	print_array(array, size);
}


/**
* sol_one- func
* @array: int *
* @size: size_t
* Return: void
*/
void sol_one(int *array, size_t size)
{
	size_t olp = size, ulp = 0, end = 0, mid = 0;

	do {
		ulp = olp;
		do {
			end = ulp;
			mid = end / 2;
			while ((mid > 0) && (array[end - 1] > array[mid - 1]))
			{
				swap(array, size, end - 1, mid - 1);
				end /= 2;
				mid = end / 2;
			}
			ulp--;
		} while (ulp);
		swap(array, size, 0, olp - 1);
		olp--;
	} while (olp > 1);
}
