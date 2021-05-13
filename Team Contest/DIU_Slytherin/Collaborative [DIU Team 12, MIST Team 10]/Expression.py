# import sys

# sys.stdin = open('in.txt', 'r')
# sys.stdout = open('out.txt', 'w')

t = int(input())
ca = 1

# print(t)
while t:

	s = input()
	digit = input()

	digit = ''.join(sorted(digit))

	left = 0
	right = len(digit) - 1

	negative = []
	numbers = []

	now = 0
	prev = -1

	original = s

	# s = '(' + s + ')'

	z = ''

	p = 0; q= 0

	for i in range(len(s)):
		if s[i] == '#':
			if i == 0 or s[i - 1] != '#':
				z += '('

		else:
			if i > 0 and s[i - 1] == '#':
				z += ')'

		z += s[i]

	if (s[len(s) - 1] == '#'):
		z += ')'

	s = z


	negative.append(0)

	res = ''
	num = ''

	for i in range(len(s)):

		# print(prev)

		if s[i] == '(':
			if i > 0 and s[i-1] == '-':
				negative.append(now)

				now = 0 if now else 1

			else:
				negative.append(now)

		elif s[i] == ')':
			now = negative.pop()

		elif s[i] == '#':
			if now:
				num += digit[left]
				res += digit[left]
				left += 1

			else:
				num += digit[right]
				res += digit[right]
				right -= 1

			prev = now

			continue

		if num:
			if prev:
				# print('-{}'.format(num))
				numbers.append(-1 * int(num))
			else:
				# print('+{}'.format(num))
				numbers.append(int(num))

		num = ''

		res += s[i]

	if num:
		if prev:
			numbers.append(-1 * int(num))
		else:
			# print('+{}'.format(num))
			numbers.append(int(num))

	pos = {}
	neg = {}

	for i in numbers:
		if i >= 0:
			l = len(str(i))
			if l not in pos:
				pos[l] = []

			pos[l].append(i)

		else:
			l = len(str(i))
			if l not in neg:
				neg[l] = []

			neg[l].append((i * -1))

	# posLength = {}

	for i in range(1, 9):
		if i in pos:
			pos[i].sort(reverse=True)
		if i in neg:
			neg[i].sort(reverse=True)

	for i in range(len(numbers)):
		if numbers[i] >= 0:
			l = len(str(numbers[i]))

			n = pos[l].pop()

			numbers[i] = n

		else:
			l = len(str(numbers[i]))

			n = neg[l].pop()

			numbers[i] = n

	out = ''

	# print(numbers)
	print('Case {}:'.format(ca))

	j = 0; k = 0; st = 0; br = 0

	for i in range(len(original)):
		if original[i] == '#':
			k += 1


			if not st:
				n = numbers[j]
				# print(n, end="")
				out += str(n)
				j += 1

			st = 1
			# n = numbers[j]
			# j += 1
			# print(n)

			# while i < len(original) and original[i] == '#':
			# 	i += 1

			# # i -= 1

			# print(i)

		else:
			k = i
			st = 0
			# print(original[i], end="")
			out += original[i]

		if original[i] == '(':
			br += 1

		elif original[i] == ')':
			br -= 1

	if br > 0:
		out += ')'

	ca += 1

	print(out)
	print(eval(out))

	t -= 1