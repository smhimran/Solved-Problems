import sys
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')

dp = [None] * 260

def solve(n):
	if n == 2:
		return 3

	if n == 1 or n == 0:
		return 1

	if dp[n] is not None:
		return dp[n]

	dp[n] = solve(n - 1)
	dp[n] += 2 * solve(n - 2)

	return dp[n]


while True:
	try:
		n = int(input())
		print(solve(n))
		
	except EOFError:
		break