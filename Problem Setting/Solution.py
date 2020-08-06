import sys
from math import sqrt
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out2.txt', 'w')

t = int(input())
ca = 1

while t:
	n=int(input())
	a = list(map(int, input().split()))
	mn = max(a)
	for i in a:
		k = sqrt(i)
		z = int(k)
		if k - z ==0:
			if i%2==0:
				mn = min(mn, i)

	print('Case {}: {}'.format(ca, mn))
	ca += 1

	t-=1