#include "slide_line.h"


/**
* slide_line- func
* @line: int *
* @size: size_t
* @direction: int
* Return: int
*/
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
		sl(line, size);
	else if (direction == SLIDE_RIGHT)
		sr(line, size);
	else
		return (0);
	return (1);
}


/**
* sl- func
* @line: int *
* @size: size_t
* Return: void
*/
void sl(int *line, size_t size)
{
	size_t pr = 0, a = 1;

	while (a < size)
	{
		while ((line[a] == 0) && (a < size))
			a++;
		if ((a < size) && line[a])
		{
			if (pr != a)
				if (line[pr])
					if (line[pr] != line[a])
						pr++;
					else
					{
						line[pr] += line[a];
						line[a] = 0;
						pr++;
						a++;
					}
				else
				{
					line[pr] += line[a];
					line[a] = 0;
					a++;
				}
			else
				a++;
		}
	}
}


/**
* slider- func
* @line: int *
* @size: size_t
* Return: void
*/
void sr(int *line, size_t size)
{
	size_t pr = size - 1, a = size - 2;

	while (a < size)
	{
		while ((line[a] == 0) && (a < size))
			a--;
		if ((a < size) && line[a])
		{
			if (pr != a)
				if (line[pr])
					if (line[pr] != line[a])
						pr--;
					else
					{
						line[pr] += line[a];
						line[a] = 0;
						pr--;
						a--;
					}
				else
				{
					line[pr] += line[a];
					line[a] = 0;
					a--;
				}
			else
				a--;
		}
	}
}
