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

	if (!array || (size < 1))
		exit(1);
	temp = malloc(sizeof(int) * size);
	if (!temp)
		exit(1);
	msr(array, size, temp);
	free(temp);
}


/**
* msr- func
* @array: int *
* @size: size_t
* @temp: int *
* Return: void
*/
void msr(int *array, size_t size, int *temp)
{
	size_t pi = 0, pf = 0, pm = 0, mid = 0, i = 0;

	if (size > 1)
	{
		mid = size / 2;
		msr(array, mid, temp);
		msr(array + mid, size - mid, temp);

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
