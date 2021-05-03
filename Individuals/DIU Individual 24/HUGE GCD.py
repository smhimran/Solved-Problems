import sys
from math import gcd
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')


n = int(input())
a = list(map(int, input().split()))

m = int(input())
b = list(map(int, input().split()))

A = 1; B = 1

for i in a:
	A *= i

for i in b:
	B *= i

G = gcd(A, B)

ans = str(G)

if len(ans) <= 9:
	print(ans)

else:
	print(ans[-9:])