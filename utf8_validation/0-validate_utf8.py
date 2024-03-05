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
    if (res):
        return (True)
    else:
        return (False)
