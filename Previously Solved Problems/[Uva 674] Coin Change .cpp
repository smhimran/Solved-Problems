#include<bits/stdc++.h>
using namespace std;
int coins[]={1,5,10,25,50};
int N;
int dp[6][8000];

int solve (int i, int sum)
{
    if (i==N)
        return !sum;
    if (dp[i][sum]!=-1) return dp[i][sum];
    int r1=0, r2=0;
    if (sum-coins[i]>=0)
        r1=solve(i, sum-coins[i]);
    r2=solve(i+1, sum);
    return dp[i][sum]=r1+r2;
}
int main()
{
    int val;
    N=sizeof(coins)/sizeof(coins[0]);
    memset(dp, -1, sizeof dp);
    while (scanf("%d", &val)!=EOF) {
        printf("%d\n", solve(0, val));
    }
    return 0;
}
