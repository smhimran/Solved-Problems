#include<bits/stdc++.h>
using namespace std;
#define inf 1<<28
int dp[101][101], banana[101][101];
int n;

int solve (int i, int j)
{
    if (i==n || j==n) return 0;
    if (dp[i][j]!=-1) return dp[i][j];
    int ret= -inf;
    ret=max(ret, solve(i+1, j)+banana[i][j]);
    ret=max(ret, solve(i, j+1)+banana[i][j]);
    return dp[i][j]=ret;
}

int main()
{
    int t, ca=1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            int row=i;
            for (int col=0; col<=i; col++, row--)
                scanf("%d", &banana[row][col]);
        }
        for (int i=1; i<n; i++) {
            int row=n-1;
            for (int col=i; col<n; col++, row--)
                scanf("%d", &banana[row][col]);
        }
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", ca++, solve(0, 0));
    }
    return 0;
}
