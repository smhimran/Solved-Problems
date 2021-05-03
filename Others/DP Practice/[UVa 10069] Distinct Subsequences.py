import sys
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')

T = int(input())

while T:

	s = input()
	t = input()

	n = len(s) + 1
	m = len(t) + 1

	dp = []

	for i in range(n):
		dp.append([0] * m)

	for i in range(n):
		dp[i][0] = 1

	for i in range(1, n):
		for j in range(1, m):
			dp[i][j] = dp[i-1][j]
			if s[i-1] == t[j-1]:
				dp[i][j] += dp[i-1][j-1]


	print(dp[n-1][m-1])

	T-= 1