import sys
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')

dp = [0] * 1005

dp[0] = 1
dp[1] = 2
dp[2] = 5
dp[3] = 13

for i in range(4, 1001):
	dp[i] = dp[i-2] + dp[i-3] + 2 * dp[i -1]

while True:

	try:
		n = int(input())
		print(dp[n])

	except EOFError:
		break