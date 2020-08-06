#include<bits/stdc++.h>
using namespace std;
int note[22];
long long dp[25][10004];
int n;

void precal ()
{
    for (int i=1; i<22; i++) {
        note[i]=(int)pow(i+0.0000001, 3);
    }
}

long long solve (int i, int amount)
{
    if (i>=22) {
        if (amount==0) return 1;
        return 0;
    }
    if (dp[i][amount]!=-1) return dp[i][amount];
    long long r1=0, r2=0;
    if (amount-note[i]>=0)
        r1=solve(i, amount-note[i]);
    r2=solve(i+1, amount);
    return dp[i][amount]=r1+r2;
}

int main()
{
    precal();
    while (cin>>n) {
        memset(dp, -1, sizeof dp);
        cout<<solve(1, n)<<endl;
    }
    return 0;
}
