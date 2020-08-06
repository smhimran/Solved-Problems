import sys
sys.stdout = open('in.txt', 'w')

from random import randint as ran

T = 300000
mx = 1000000
sz = 300000

print('{} {}'.format(T, sz))

l = []
dic = {}

while len(l)<sz:
	n = ran(1, mx)
	if n in dic:
		continue
	l.append(n)
	dic[n]=1

l.sort(reverse=True)

for i in l:
	print(i, end=' ')
print()

while T:
	n = ran(1, mx)
	print(n)

	T-=1
