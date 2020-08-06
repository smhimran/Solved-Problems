#include<bits/stdc++.h>
using namespace std;

long long dp[55];

long long fibonacci(int n)
{
    if (n==1) return 1;
    if (n==2) return 2;
    if (dp[n]!=-1) return dp[n];
    return dp[n]=fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    memset(dp, -1, sizeof dp);
    int n;
    while (cin>>n && n) {
        cout<<fibonacci(n)<<endl;
    }
    return 0;
}
