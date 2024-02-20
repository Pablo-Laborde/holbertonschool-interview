#include "sandpiles.h"

int main(void)
{
	int grid1[3][3] = {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}
    };
    int grid2[3][3] = {
        {1, 3, 1},
        {3, 3, 3},
        {1, 3, 1}
    };
	sandpiles_sum(grid1, grid2);
	return (0);
}


/**
* sandpiles_sum- func
* @grid1: int **
* @grid2: int **
* Return: void
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	print_sum_sp(grid1, grid2);
	for (i = 0; i< 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	do {
		printf("=\n");
	} while (toppling(grid1));
}

/**
* toppling- func
* @grid: int **
* Return: int
*/
int toppling(int grid[3][3])
{
	int	flag, i, j, m, n;

	flag = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
			{
				grid[i][j] -= 4;
				for (m = i - 1; m <= i + 1; m++)
					for (n = j - 1; n <= j + 1; n++)
						if ((m == i && (j == -1 || j == 1))
							|| (n == j && (i == -1 || i == 1)))
						{
							grid[m][n] += 1;
							if (grid[m][n] > 3)
								flag = 1;
						}
			}
	print_sp(grid);
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
