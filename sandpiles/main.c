#include "sandpiles.h"


/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
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
		int grid3[3][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    print_sum_sp(grid1, grid3);

    sandpiles_sum(grid1, grid3);

    printf("=\n");
    print_sp(grid1);

    return (EXIT_SUCCESS);
}