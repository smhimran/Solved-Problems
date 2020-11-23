import sys
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')

ans = []

def precal():
	ans.append(0)
	ans.append(0)
	ans.append(1)
	ans.append(1)

	for i in range(4, 1001):
		ans.append(ans[i-1] + 2 * ans[i-2])


precal()

while True:
	try:
		n = int(input())
		print(ans[n])
	except EOFError:
		break