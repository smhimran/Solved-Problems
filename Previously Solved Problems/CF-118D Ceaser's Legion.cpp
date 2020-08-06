#include<bits/stdc++.h>
using namespace std;
#define mod 100000000
int k1, k2, n1, n2;
int dp[101][101][11][11];
int solve (int f, int h, int i, int j)
{
    if (dp[f][h][i][j]!=-1)
        return dp[f][h][i][j];
    if (f+h==0)
        return 1;
    int r1=0, r2=0;
    if (i<k1 && f>0)
        r1=solve(f-1, h, i+1, 0)%mod;
    if (j<k2 && h>0)
        r2=solve(f, h-1, 0, j+1)%mod;
    return dp[f][h][i][j]=(r1+r2)%mod;
}

int main()
{
    cin>>n1>>n2>>k1>>k2;
    memset(dp, -1, sizeof dp);
    cout<<solve(n1, n2, 0, 0)<<endl;
    return 0;
}
