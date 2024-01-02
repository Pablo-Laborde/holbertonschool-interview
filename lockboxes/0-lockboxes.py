#!/usr/bin/python3
""" ex 0 """


def canUnlockAll(boxes):
  length = len(boxes)
  rv = True
  dic = {0: True}
  for i in range(length):
    if i not in dic:
      dic[i] = False
  unlockBox(dic, boxes, 0)
  for each in dic:
    if dic[each] is False:
      rv = False
  return (rv)


def unlockBox(dic, boxes, pos):
  for each in boxes[pos]:
    if (each in dic) and (dic[each] is False):
      dic[each] = True
      unlockBox(dic, boxes, each)
