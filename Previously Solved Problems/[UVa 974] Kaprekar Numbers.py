#Dhur mia
ls=[False]*40001
def pre():
    ls[9]=True
    for i in range(2,40001):
        n=i**2
        s=str(n)
        for j in range(1, len(s)-1):
            x, y=s[:j], s[j:]
            x=int(x)
            y=int(y)
            if x!=0 and y!=0 and x+y==i:
                ls[i]=True
            

pre()
t=int(input())
a=1
while a<=t:
    p, q= map(int, input().split())
    if a>1:
        print()
    print("case #{}".format(a))
    f=False
    for i in range(p, q+1):
        if ls[i]==True:
            print(i)
            f=True
    
    if f==False:
        print("no kaprekar numbers")
    # print()   
    a+=1
        