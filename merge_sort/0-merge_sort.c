#include "sort.h"


/**
* merge_sort- func
* @array: int *
* @size: size_t
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;
	size_t pi = 0, pf = 0, pm = 0, mid = 0, i = 0;

	if (array && (size > 1))
	{
		mid = size / 2;
		merge_sort(array, mid);
		merge_sort(array + mid, size - mid);

		temp = malloc(sizeof(int) * size);
		if (!temp)
			exit(1);
		printf("Merging...\n");
		printf("[left]: ");
		print_line(array, mid);
		printf("[right]: ");
		print_line(array + mid, size - mid);
		for (pm = mid; pf < size; pf++)
		{
			if ((pi < mid) && (pm < size))
			{
				if (array[pi] < array[pm])
					temp[pf] = array[pi];
				else
					temp[pf] = array[pm];
				(array[pi] < array[pm]) ? pi++ : pm++;
			}
			else
				(pi < mid) ? ((temp[pf] = array[pi]), pi++) :
					((temp[pf] = array[pm]), pm++);
		}
		for (; i < size; i++)
			array[i] = temp[i];
		free(temp);
		printf("[Done]: ");
		print_line(array, size);
	}
}


/**
* print_line- func
* @array: int *
* @size: size_t
* Return: void
*/
void print_line(int *array, size_t size)
{
	size_t i = 0;

	for (; i < size; i++)
	{
		if (i)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
