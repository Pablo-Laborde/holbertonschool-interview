#!/usr/bin/python3
"""pascal_triangle
0-pascal_triangle.py

This module creates a pascal triangle.

Functions:
pascal_triangle: creates the mentioned triangle.

Usage:
    Import and use it.
"""


def pascal_triangle(n):
    """pascal_triangle
    Returns a Pascal Triangle

    Args:
        n: integer

    Returns:
        list: list of integers
    """
    pt_arr = []
    if (n > 0):
        pt_arr.append([1])
        for i in range(1, n):
            lvl = []
            for j in range(i + 1):
                aux = 0
                if (j > 0):
                    aux += pt_arr[i - 1][j - 1]
                if (j < i):
                    aux += pt_arr[i - 1][j]
                lvl.append(aux)
            pt_arr.append(lvl)
    return pt_arr
