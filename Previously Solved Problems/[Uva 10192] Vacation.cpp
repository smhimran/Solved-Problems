#include<bits/stdc++.h>
using namespace std;
string a, b;
int dp[101][101];

int solve(int i, int j)
{
    if (a[i]=='\0' || b[j]=='\0') return 0;
    if (dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if (a[i]==b[j])
        ans=1+solve(i+1, j+1);
    else {
        ans=max(ans, solve(i+1, j));
        ans=max(ans, solve(i, j+1));
    }
    return dp[i][j]=ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int ca=1;
    while (getline(cin, a), a[0]!='#') {
        getline(cin, b);
        memset(dp, -1, sizeof dp);
        int ans=solve(0, 0);
        printf("Case #%d: you can visit at most %d cities.\n", ca++, ans);
    }
    return 0;
}
