#!/usr/bin/python3
""" ex 0 """


def minOperations(n):
	import math
	if (n > 1):
		sr = int(math.sqrt(n))
		mlo = sr
		while (n % mlo):
			mlo -= 1
		mls = int(n / mlo)
		if (mlo == 1):
			return (mls)
		else:
			axo = minOperations(mlo)
			axs = minOperations(mls)
			if ((mlo + axs) < (mls + axo)):
				return (mlo + axs)
			else:
				return (mls + axo)
	else:
		return (0)


if __name__ == "__main__":
	print(minOperations(240))