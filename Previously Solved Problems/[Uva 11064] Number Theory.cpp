#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
    int res=n, phi=1;
    int div=1;
    for (int i=2; i<=n/i; ++i) {
        if (n%i==0) {
            int x=0, y=1;
            while (n%i==0) {
                n/=i;
                ++x;
                y*=i;
            }
            div*=(x+1);
            phi*=(y- y/i);
        }
    }
    if (n>1) {
        div*=2;
        phi*=n-1;
    }
    return res-div-phi+1;
}

int main()
{
    int n;
    while (scanf("%d", &n)!=EOF) {
        printf("%d\n", solve(n));
    }
    return 0;
}
