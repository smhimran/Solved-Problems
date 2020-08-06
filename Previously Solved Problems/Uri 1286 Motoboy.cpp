#include<bits/stdc++.h>
using namespace std;

int weight[1002];
int tim[1002];
int dp[1002][1002];
int cap;

int solve (int i, int w, int n)
{
    if (i==n) return 0;
    if (dp[i][w]!=-1) return dp[i][w];
    int t1, t2;
    if (w+weight[i]<=cap)
        t1=tim[i]+solve(i+1, w+weight[i], n);
    else t1=0;
    t2=solve(i+1, w, n);
    dp[i][w]=max(t1, t2);
    return dp[i][w];
}

int main()
{
    int n;
    while (scanf("%d", &n) && n) {
        cin>>cap;
        for (int i=0; i<n; i++)
            cin>>tim[i]>>weight[i];
        memset(dp, -1, sizeof dp);
        cout<<solve(0, 0, n)<<" min."<<endl;
    }
    return 0;
}
