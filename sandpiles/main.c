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
	print_sum_sp(grid1, grid2);
	sandpiles_sum(grid1, grid2);
	print_sp(grid1);
	return (0);
}
