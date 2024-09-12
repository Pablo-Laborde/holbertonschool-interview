#!/usr/bin/python3
"""Prime Game excercise"""


def isWinner(x, nums):
    """Is Winner function"""
    if (x == 0):
        return (None)
    d = {"Maria": 0, "Ben": 0}
    p = ["Maria", "Ben"]
    for i in range(x):
        w = 1
        num = nums[i]
        nums_dict = {n: True for n in range(2, num + 1)}
        for j in range(2, num + 1):
            if (nums_dict[j]):
                k = j
                w = 0 if (w == 1) else 1
                while (k <= (nums[i] + 1)):
                    nums_dict[k] = False
                    k += j
        d[p[w]] += 1
    return p[0] if d[p[0]] > d[p[1]] else p[1]
