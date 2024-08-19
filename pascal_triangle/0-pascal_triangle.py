#!/usr/bin/python3
"""Pascal Triangle."""


def pascal_triangle(n):
    """Pascal Triangle function."""
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
