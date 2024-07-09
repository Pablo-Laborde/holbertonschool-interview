#!/usr/bin/python3
"""Making change."""


def makeChange(coins, total):
    """Make change function."""
    if (total <= 0):
        return (0)
    result = loop_of_options(sorted(coins, reverse=True), total)
    """print(result)"""
    if not result:
        return (-1)
    return (result)


def loop_of_options(coins, total):
    """Loop recursion."""
    if len(coins) == 0:
        return (0)
    a = total // coins[0]
    """print(f"{coins[0]} -> a: {a}")"""
    for i in range(a, -1, -1):
        temp = total - (coins[0] * i)
        if (temp == 0):
            return (a)
        else:
            b = loop_of_options(coins[1:], temp)
            if b:
                return (a + b)
    return (0)
