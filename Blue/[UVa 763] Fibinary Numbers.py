import sys
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')


fibo = [10] * 105

fibo[0] = 1
fibo[1] = 2

for i in range(2, 105):
	fibo[i] = fibo[i-1] + fibo[i-2]

second = False

while True:
	
	try:
		a = input()
		b = input()
		n = 0
		m = 0

		ind = len(a) - 1

		for i in a:
			if i == '1':
				n += fibo[ind]

			ind -= 1

		ind = len(b) - 1

		for i in b:
			if i == '1':
				m += fibo[ind]

			ind -= 1

		n += m

		ans = ''

		started = False

		for i in range(104, -1, -1):
			if n >= fibo[i]:
				n -= fibo[i]
				ans += '1'
				started = True

			elif started == True:
				ans += '0'


		if ans == '':
			ans = '0'

		if second:
			print()

		print(ans)

		second = True


		c = input()

	except EOFError:
		break