import sys
from math import gcd

sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')


t = int(input())

while t > 0:
	n = int(input())

	a = list(map(int, input().split()))

	prod = 1; now = 1

	for i in a:
		prod *= i

	for i in range(len(a)):
		now *= a[i]
		left = prod // now

		if (gcd(now, left) == 1):
			print(i+1)
			break

	t -= 1