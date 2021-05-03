import sys
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')

s = ""

while len(s) < 100005:
	s += 'abcd'

n = int(input())

print(s[:n])