import sys
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')

a = int(input())
b = int(input())
c = int(input())

l = [a, b, c]

found = False

for i in l:
	for j in l:
		if i+j in l:
			print('YES')
			found = True
			break

	if found:
		break

if found == False:
	print('NO')