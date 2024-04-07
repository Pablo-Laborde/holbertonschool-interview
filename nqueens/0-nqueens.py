#!/usr/bin/python3
"""This is nqueens program."""


import sys


def nqueens():
    """Check if the format is correct."""
    if (len(sys.argv) != 2):
        print("Usage: nqueens N")
        exit(1)
    try:
        n = int(sys.argv[1])
    except Exception:
        print("N must be a number")
        exit(1)
    if (n < 4):
        print("N must be at least 4")
        exit(1)
    psol = []
    recsol(psol, n, [])
    print_result(psol)


def recsol(psol, n, pos):
    """Find all the solutions recursively."""
    con = True
    for i in range(n):
        for j in range(n):
            act = [i, j]
            for each in pos:
                con *= iniline(n, each, act)
            if (con):
                pos.append(act)
                if (len(pos) == n):
                    perm_filter(psol, pos)
                else:
                    recsol(psol, n, pos)
                pos.remove(act)
            else:
                con = True


def iniline(n, p1, p2):
    """Check if ptwo is in line of pone."""
    if (p1[0] == p2[0]):
        return (False)
    if (p1[1] == p2[1]):
        return (False)
    if ((p1[0] + p1[1]) == (p2[0] + p2[1])):
        return (False)
    if ((p1[1] - p1[0]) == (p2[1] - p2[0])):
        return (False)
    return (True)


def perm_filter(psol, pos):
    """Doesn't allow to add permutations."""
    perm = 1
    for el1 in psol:
        eq = 0
        for el2 in pos:
            if (el2 not in el1):
                eq = 1
        perm *= eq
    if (perm):
        psol.append(list(pos))


def print_result(psol):
    """Print the solution."""
    for each in psol:
        print(each)


if __name__ == "__main__":
    nqueens()
