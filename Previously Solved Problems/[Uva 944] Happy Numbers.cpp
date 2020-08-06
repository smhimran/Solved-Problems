#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int hap[100000];
int cnt;
int numSquareSum(int n)
{
    int squareSum = 0;
    while (n)
    {
        squareSum += (n % 10) * (n % 10);
        n /= 10;
    }
    return squareSum;
}

bool isHappy(int n)
{
    cnt=0;
    int slow, fast;
    slow=fast=n;
    do {
        slow=numSquareSum(slow);
        fast=numSquareSum(numSquareSum(fast));
        cnt++;
    } while (slow!=fast);
    return (fast==1);
}

void precal()
{
    hap[1]=1;
    for (int i=2; i<=99999; i++) {
        if (isHappy(i)) hap[i]=cnt+1;
    }
}

int main() {
    precal();
    int l, h, ca=0;
    while (cin>>l>>h) {
        if (ca) cout<<endl;
        for (int i=l; i<=h; i++) {
            if (hap[i])
                cout<<i<<" "<<hap[i]<<endl;
        }
        ca++;
    }
	return 0;
}
