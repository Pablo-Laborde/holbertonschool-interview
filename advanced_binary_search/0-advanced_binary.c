/*Excercise 0*/


#include "search_algos.h"

/**
* advanced_binary- func
* @array: int *
* @size: size_t
* @value: int
* Return: int
*/
int advanced_binary(int *array, size_t size, int value)
{
	size_t i = 0;
	int pos = 0, flag = 0, tmp = 0;

	if (!array || !size)
		return (-1);
	printf("Searching in array: ");
	for (; i < size; i++)
	{
		if (i)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
	size--;
	pos = size / 2;
	flag = ((pos > 0) && (array[pos - 1] == value))
	if ((array[pos] == value) && !flag)
		return (pos);
	if ((array[pos] < value) && !flag)
	{
		tmp = advanced_binary(array + pos + 1, size - pos, value);
		return ((tmp == -1) ? -1 : (pos + 1 + tmp));
	}
	else
		return (advanced_binary(array, size - pos, value));
}
