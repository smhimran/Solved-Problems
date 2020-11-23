import sys
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')

def reVal(num): 
  
    if (num >= 0 and num <= 9): 
        return chr(num + ord('0')); 
    else: 
        return chr(num - 10 + ord('A')); 


def strev(str): 
  
    len = len(str); 
    for i in range(int(len / 2)): 
        temp = str[i]; 
        str[i] = str[len - i - 1]; 
        str[len - i - 1] = temp; 
  

def fromDeci(res, inputNum, base): 
   
    while (inputNum > 0): 
        res+= reVal(inputNum % base); 
        inputNum = int(inputNum / base); 
  
    res = res[::-1]; 
  
    return res;



while True:
	try:
		l = list(input().split())
		a = int(l[1])
		b = int(l[2])

		s = l[0]

		try:
			n = int(s, a)
			ans = ''
			if n == 0:
				ans = '0'
			else: 
				ans = fromDeci(ans, n, b)

			if len(ans) > 7:
				print('ERROR'.rjust(7))

			else:
				print(ans.rjust(7))

		except:
			print('ERROR'.rjust(7))

			

	except EOFError:
		break
