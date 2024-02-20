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
