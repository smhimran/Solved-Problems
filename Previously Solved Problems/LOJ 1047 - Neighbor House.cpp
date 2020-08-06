#include<bits/stdc++.h>
using namespace std;
#define inf 1000000009
int r[23], g[23], b[23];
int dp[25][5];
int n;

int solve ()
{
    for (int i=1; i<=n; i++) {
        dp[i][0]=min(dp[i-1][1], dp[i-1][2])+r[i];
        dp[i][1]=min(dp[i-1][0], dp[i-1][2])+g[i];
        dp[i][2]=min(dp[i-1][0], dp[i-1][1])+b[i];
    }
    return min(dp[n][0], min(dp[n][1], dp[n][2]));
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, ca=1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=1; i<=n; i++)
            scanf("%d %d %d", r+i, g+i, b+i);
        memset(dp, 0, sizeof dp);
        printf("Case %d: %d\n", ca++, solve());
    }
    return 0;
}
