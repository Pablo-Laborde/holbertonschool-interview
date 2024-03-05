#!/usr/bin/python3
"""Excercise 0."""


def validUTF8(data):
    """Desc. function validUTF8."""
    fo = 0b11110000100000001000000010000000
    th = 0b111000001000000010000000
    tw = 0b1100000010000000
    on = 0b10000000
    res = 1
    for ec in data:
        res *= ((ec & fo == fo) or (ec & th == th) or
                (ec & tw == tw) or (ec & on != on))
        #print(" ", ec)
        #print("Four : ", bin((ec & fo)), (ec & fo == fo))
        #print("Three: ", bin((ec & th)), (ec & th == th))
        #print("Two  : ", bin((ec & tw)), (ec & tw == tw))
        #print("One  : ", bin((ec & on)), (ec & on != on))
        #print("       ", bin(ec))
        #print(((ec & fo == fo) or (ec & th == th) or (ec & tw == tw) or (ec & on != on)))
        #print()
    if (res):
        return (True)
    else:
        return (False)
