#!/usr/bin/python3
"""Exercise 0."""


def rain(walls):
    """Rain function."""
    """print(walls)"""
    le = len(walls)
    volume = 0
    w1 = 0
    while ((w1 < le) and (walls[w1] == 0)):
        w1 += 1
    w2 = w1 + 1
    while (w2 < le):
        rp = w2
        for i in range(w2, le):
            if (walls[i] > walls[rp]):
                rp = i
            if (walls[i] > walls[w1]):
                break
        w2 = rp
        if (walls[w1] > walls[w2]):
            h = walls[w2]
        else:
            h = walls[w1]
        w = w2 - w1 - 1
        """print(f"{w1}: {walls[w1]} | {w2}: {walls[w2]}")"""
        for j in range(w1 + 1, w2):
            volume += h - walls[j]
        w1 = w2
        w2 += 1
    return (volume)
