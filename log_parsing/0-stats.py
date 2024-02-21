#!/usr/bin/python3
""" documentation """

import sys
import signal


sc = [200, 301, 400, 401, 403, 404, 405, 500]
scdic = {**{key: 0 for key in sc}}
fsdic = {'fs': 0}

def sigint_func(sig, frame):
	""" function when ctrl + c """
	print(f"File size: {fsdic['fs']}")
	for key, value in (sorted(scdic.items(), key=lambda item: item[1], reverse=True)):
		if (value):
			print(f"{key}: {value}")
	exit(0)


signal.signal(signal.SIGINT, sigint_func)
counter = 0
while (True):
	line = input()
	ls = line.split()
	fsdic['fs'] += int(ls[8])
	key = int(ls[7])
	scdic[key] += 1
	counter += 1
	if (counter == 10):
		counter = 0
		print(f"File size: {fsdic['fs']}")
		for key, value in (sorted(scdic.items(), key=lambda item: item[1], reverse=True)):
			if (value):
				print(f"{key}: {value}")
