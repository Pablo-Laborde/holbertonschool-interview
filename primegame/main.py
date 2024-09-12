#!/usr/bin/python3

isWinner = __import__('0-prime_game').isWinner


print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))

print("Winner: {}".format(isWinner(3, [2, 2, 2])))

print("Winner: {}".format(isWinner(0, [])))

print("Winner: {}".format(isWinner(7, [2, 5, 1, 4, 3, 2, 2])))

print("Winner: {}".format(isWinner(-1, [2, 2, 2])))


lista = [x for x in range(2, 10002)]
print("Winner: {}".format(isWinner(10000, lista)))
