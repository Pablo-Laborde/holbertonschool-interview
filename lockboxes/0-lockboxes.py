#!/usr/bin/python3
""" ex 0 """

def canUnlockAll(boxes):
	length = len(boxes)
	dic = {0: True}
	for i in range(length):
		if i not in dic:
			dic[i] = False
	unlockBox(dic, boxes, 0)


def unlockBox(dic, boxes, pos):
	for each in boxes[pos]:
		if (each in dic) and (dic[each] == False):
			dic[each] = True
			unlockBox(dic, boxes, each)


canUnlockAll([[1], [2]])