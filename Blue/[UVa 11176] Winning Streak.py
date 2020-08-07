import sys
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')

from math import factorial

f = [1, 1]

for i in range(2, 501):
	f.append(factorial(i))

while True:
	n, p = input().split()
	if n == '0':
		break
	n = int(n)
	p = float(p)
	ans = 0.0
	for i in range(1, n):
		prob = p*(i)
		loss_prob = (1.0 - p) * (n-i)
		perm = f[n] / (f[i] * f[n-i])
		ans += prob * loss_prob * perm

	ans += p*n
	print(ans)