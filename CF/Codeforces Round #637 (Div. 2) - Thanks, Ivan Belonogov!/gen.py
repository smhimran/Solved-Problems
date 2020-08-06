import sys,random
sys.stdout = open('in.txt', 'w')

print(100)
print(1000)
for i in range(1, 1001):
	print(i, end=" ")
print()
for t in range(98):
	l=[1,]
	for i in range(2, 1001):
	    l.append(i);
	    
	random.shuffle(l)

	print(1000)
	for i in l:
	    print(i, end=" ")
	print()

print(1000)
for i in range(1000, 0, -1):
	print(i, end=" ")
print()