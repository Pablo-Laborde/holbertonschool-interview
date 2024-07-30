#!/usr/bin/python3
"""Island perimeter excercise."""


def island_perimeter(grid):
    """Island perimeter functions."""
    perimeter = 0
    m = len(grid)
    for i in range(m):
        n = len(grid[i])
        for j in range(n):
            if (grid[i][j] == 1):
                perimeter += mini_grid(grid, i, j)
    return (perimeter)


def mini_grid(grid, i, j):
    """This function goes through a mini grid."""
    perimeter = 0
    m = len(grid)
    n = len(grid[i])
    if ((i == 0) or (grid[i - 1][j] == 0)):
        perimeter += 1
    if ((i == (m - 1)) or (grid[i + 1][j] == 0)):
        perimeter += 1
    if ((j == 0) or (grid[i][j - 1] == 0)):
        perimeter += 1
    if ((j == (n - 1)) or (grid[i][j + 1] == 0)):
        perimeter += 1
    return (perimeter)
