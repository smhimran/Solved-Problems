import sys
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')


t = int(input())

while t:

	p, a, b, c = map(int, input().split())

	ans = 9999999999999999999999

	if p % a == 0 or p % b == 0 or p % c == 0:
		ans = 0

	else:
		ans = min(ans, ((((p//a) + 1) * a) - p))
		ans = min(ans, ((((p//b) + 1) * b) - p))
		ans = min(ans, ((((p//c) + 1) * c) - p))

	print(ans)

	t -= 1