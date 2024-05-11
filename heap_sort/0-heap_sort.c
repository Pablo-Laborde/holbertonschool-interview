#include "sort.h"


/**
* heap_sort- func
* @array: int *
* @size: size_t
* Return: void
*/
void heap_sort(int *array, size_t size)
{
	size_t p1 = size, p2 = size, end = 0, mid = 0;
	int change = 0, a = 0;

	do {
		p2 = p1;
		change = 0;
		do {
			end = p2;
			mid = end / 2;
			while ((mid > 0) && (array[end - 1] > array[mid - 1]))
			{
				a = array[end - 1];
				array[end - 1] = array[mid - 1];
				array[mid - 1] = a;
				change = 1;
				end /= 2;
				mid = end / 2;
				print_array(array, size);
			}
			p2--;
		} while (p2);
		if (change)
		{
			a = array[0];
			array[0] = array[p1 - 1];
			array[p1 - 1] = a;
			print_array(array, size);
			p1--;
		}
	} while (change);
}
