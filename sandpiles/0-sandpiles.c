#include "sandpiles.h"


/**
* sandpiles_sum- func
* @grid1: int **
* @grid2: int **
* Return: void
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int flag, nf;

	flag = sum(grid1, grid2);
	while (flag)
	{
		printf("=\n");
		print_sp(grid1);
		nf = toppling(grid1);
		flag = nf;
	}
}

/**
* toppling- func
* @grid: int **
* Return: int
*/
int toppling(int grid1[3][3])
{
	int	flag, i, j, m, n;
	int ga[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

	flag = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				for (m = (i - 1); m < (i + 2); m++)
					for (n = (j - 1); n < (j + 2); n++)
						if ((m >= 0) && (m < 3) && (n >= 0) && (n < 3))
							if (((m == i) && ((n == (j - 1)) || (n == (j + 1))))
								|| ((n == j) && ((m == (i - 1)) || (m == (i + 1)))))
								ga[m][n]++;
			}
	return (sum(grid1, ga));
}

/**
* sum- func
* @grid1: int **
* @grid2: int **
* Return: int
*/
int sum(int grid1[3][3], int grid2[3][3])
{
	int flag, i, j;

	flag = 0;
	for (i = 0; i< 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
				flag = 1;
		}
	return (flag);
}

/**
* print_sum_sp- func
* @grid1: int **
* @grid2: int **
* Return: void
*/
void print_sum_sp(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid1[i][j]);
		}
		if (i == 1)
			printf(" + ");
		else
			printf("   ");
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid2[i][j]);
		}
		printf("\n");
	}
}

/**
* print_sp- func
* grid: int**
* Return: void
*/
void print_sp(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
