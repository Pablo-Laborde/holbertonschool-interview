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
	/* V1 */
	/*
	if (direction == SLIDE_LEFT)
		sl(line, size);
	else if (direction == SLIDE_RIGHT)
		sr(line, size);
	else
		return (0);
	return (1);
	*/

	/* V2 */
	if (direction == SLIDE_LEFT)
		slider(line, size, 0, 1, 1);
	else if (direction == SLIDE_RIGHT)
		slider(line, size, size - 1, size - 2, -1);
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


/**
* slider- func
* @line: int *
* @size: size_t
* @pr: size_t
* @a: size_t
* Return: void
*/
void slider(int *line, size_t size, size_t pr, size_t a, size_t add)
{
	while (a < size)
	{
		while ((line[a] == 0) && (a < size))
			a += add;
		if ((a < size) && line[a])
		{
			if (pr != a)
				if (line[pr])
					if (line[pr] != line[a])
						pr += add;
					else
					{
						line[pr] += line[a];
						line[a] = 0;
						pr += add;
						a += add;
					}
				else
				{
					line[pr] += line[a];
					line[a] = 0;
					a += add;
				}
			else
				a += add;
		}
	}
}
