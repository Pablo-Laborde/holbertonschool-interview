#include "sort.h"


/**
* radix_sort- func
* @array: int *
* @size: size_t
* Return: void
*/
void radix_sort(int *array, size_t size)
{
	size_t pos = 0;
	int lvl = 1, key = 0;
	ht **root = NULL;

	if (size > 2)
	{
		root = create_hash();
		while (!sorted(array, size))
		{
			for (pos = 0; pos < size; pos++)
			{
				key = key_maker(array[pos], lvl);
				add_elem(root, array[pos], key);
			}
			lvl++;
			hash_to_array(root, array);
			print_array(array, size);
		}
		free(root);
	}
}


/**
* key_maker- func
* @n: int
* @lvl: int
* Return: int
*/
int key_maker(int n, int lvl)
{
	int i = 1, num = 1;

	for (; i < lvl; i++)
		num *= 10;
	return ((n / num) % 10);
}


/**
* sorted- func
* @array: int *
* @size: size_t
* Return: int
*/
int sorted(int *array, size_t size)
{
	size_t i = 1;
	int rv = 1;

	while (rv && (i < size))
		(array[i - 1] < array[i]) ? i++ : (rv = 0);
	return (rv);
}
