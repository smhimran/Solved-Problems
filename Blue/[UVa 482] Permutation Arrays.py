import sys
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')

a = dict()

t = int(input())

while t > 0:
	input()
	l = list(map(int, input().split()))
	b = list(input().split())	

	mx = 0

	for i in range(len(l)):
		a[l[i]] = b[i]
		mx = max(mx, l[i])

	for i in range(1, mx+1):
		print(a[i])

	if t > 1:
		print()

	t -= 1