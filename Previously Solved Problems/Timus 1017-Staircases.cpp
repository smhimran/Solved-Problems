#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[503][503];

long long solve (int t, int k)
{
    if (t==n) {
        return 1;
    }
    if (dp[t][k]!= -1) return dp[t][k];
    dp[t][k]=0;
    for (int i=k+1; i<=n-t; i++) {
        dp[t][k]+=solve(t+i, i);
    }
    return dp[t][k];
}

int main()
{
    memset(dp, -1, sizeof dp);
    cin>>n;
    long long ans=0;
    for (int i=1; i<n; i++)
        ans+=solve(i,i);
    cout<<ans<<endl;
    return 0;
}
