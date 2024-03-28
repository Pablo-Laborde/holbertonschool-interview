#include "menger.h"


/**
* menger- function
* @level: int
* Return: void
*/
void menger(int level)
{
	int ns, i, j;

	if (level >= 0)
	{
		ns = nsize(level);
		for (i = 0; i < ns; i++)
		{
			for (j = 0; j < ns; j++)
				if (valid(level, i, j))
					printf("#");
				else
					printf(" ");
			printf("\n");
		}
	}
}


/**
* valid- func
* @level: int
* @i: int
* @j: int
* Return: int
*/
int valid(int level, int i, int j)
{
	int ns, ft, st;

	if (level)
	{
		ns = nsize(level);
		ft = ns / 3;
		st = 2 * ft;
		if (((i >= ft) && (i < st)) && ((j >= ft) && (j < st)))
			return (0);
		else
			return (valid(level - 1, i % ft, j % ft));
	}
	return (1);
}


/**
* nsize- func
* @level: int
* Return: int
*/
int nsize(int level)
{
	if (!level)
		return (1);
	else
		return (3 * nsize(level - 1));
}
