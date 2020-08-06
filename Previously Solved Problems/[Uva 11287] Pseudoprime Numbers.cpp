#include<bits/stdc++.h>
using namespace std;

long long Mod(long long x, long long y, long long m) {
    long long ans = 1, tmp = x;
    while(y) {
        if(y&1) {
            ans *= tmp;
            ans %= m;
        }
        y >>= 1;
        tmp *= tmp, tmp %= m;
    }
    return ans;
}

bool prime(int n)
{
    for (int i=2; i*i<=n; i++) {
        if (n%i==0)
            return false;
    }
    return true;
}

int main()
{
    long long p, a;
    while (scanf("%lld %lld", &p, &a) && p && a) {
        if (prime(p) || Mod(a, p, p)!=a)
            puts("no");
        else
            puts("yes");
    }
    return 0;
}
