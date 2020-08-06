#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

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
    int slow, fast;
    slow=fast=n;
    do {
        slow=numSquareSum(slow);
        fast=numSquareSum(numSquareSum(fast));
    } while (slow!=fast);
    return (fast==1);
}

int main() {
    int t, ca=1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d is %s number.\n", ca++, n, (isHappy(n))? "a Happy":"an Unhappy");
    }
	return 0;
}
