import sys
sys.stdout = open('in.txt', 'w')

import random

T = 100
mx = 1000000
sz = 10000
print(T)

s = {mx}

while T:
	print(sz)
	for i in range(sz):
		n = random.randint(1, mx)
		print(n, end=' ')

	print()

	T-=1