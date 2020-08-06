import sys
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')


inf = 1000000000

t = int(input())
input()
while t:
	a = list(map(int, input().split()))

	# print(t)
	# print(a)

	n = len(a) - 1
	nxt = []
	temp = []
	for i in range(len(a)):
		temp.append(i)
		if a[i] == -1:
			a[i] = inf


	dp = []
	nxt.append(temp)
	dp.append(a)

	while n:

		l = list(map(int, input().split()))
		temp = []
		for i in range(len(l)):
			temp.append(i)
			if l[i] == -1:
				l[i] = inf

		dp.append(l)
		nxt.append(temp)

		n-=1

	tax = list(map(int, input().split()))


	n = len(a)

	for k in range(n):
		for i in range(n):
			for j in range(n):
				if (dp[i][k] + dp[k][j] + tax[k]) < dp[i][j]:
					dp[i][j] = (dp[i][k] + dp[k][j] + tax[k])
					nxt[i][j] = nxt[i][k]


	# print(t)
	# for i in dp:
	# 	print(i)
	# for i in nxt:
	# 	print(i)
	# print(tax)

	while True:
		try:
			u, v = map(int, input().split())
			# print("{} {}".format(u, v))
			cost = dp[u-1][v-1]
			i = u-1
			v -= 1
			path = [i+1]
			while i != v:
				i = nxt[i][v]
				# cost += tax[i]
				path.append(i+1)
			# path.append(v+1)
			print('From {} to {} :'.format(u, v+1))
			print('Path: ', end='')
			for i in range(len(path)):
				if i > 0:
					print('-->', end='')
				print(path[i], end='')
			print()
			# print(path)
			print('Total cost : {}\n'.format(cost))

		except ValueError:
			break

		except EOFError:
			# print()
			break

	t -= 1
	# if t:
	# 	print()