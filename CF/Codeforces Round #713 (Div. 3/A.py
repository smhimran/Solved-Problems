import sys
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')

t = int(input())

while (t):
	
	n = int(input())
	
	a = list(map(int, input().split()))
	
	for i in range(len(a)):
		ind = i + 1
		
		if ind >= n:
			ind = 0;
		
		if a[i] != a[i-1] and a[i] != a[ind]:
			print(i + 1)
			break
	
	t -= 1