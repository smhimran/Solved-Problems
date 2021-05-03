import sys
from math import factorial as f
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')

def comb(n, k):
	
	ret = f(n)
	
	ret //= f(k)
	
	ret //= f(n - k)
	
	return ret

t = int(input())

while t:
	
	l = list(map(int, input().split()))
	
	n = l[0]
	k = l[1]
	
	l = l[2:]
	
	if k == 0:
		print(1)
		
	else:
		white = n
		
		for i in l:
			white -= i
			
		if white < k-1:
			print(0)
			
		else:
			z = white - (k - 1)
			
			print(comb(z + k, k))
			
	
	# print(l)
	
	t -= 1