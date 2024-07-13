#!/usr/bin/python3
"""Exercise 0."""


def rain(walls):
    """Rain function."""
    le = len(walls)
    volume = 0
    w1 = 0
    while ((w1 < le) and (walls[w1] == 0)):
        w1 += 1
    w2 = w1 + 1
    while (w2 < le):
        while ((w2 < (le - 1)) and (walls[w2] == 0)):
            w2 += 1
        if (walls[w1] > walls[w2]):
            h = walls[w2]
        else:
            h = walls[w1]
        w = w2 - w1 - 1
        volume += w * h
        w1 = w2
        w2 += 1
    return (volume)
