#include<bits/stdc++.h>
using namespace std;
int grid[105][105], dp[105][105];
int r, c;

int solve(int i, int j)
{
    if (dp[i][j]!=-1) return dp[i][j];
    int m=0;
    if (i>0 and grid[i-1][j]<grid[i][j]) m=max(solve(i-1, j)+1, m);
    if (j>0 and grid[i][j-1]<grid[i][j]) m=max(solve(i, j-1)+1, m);
    if (i<r-1 and grid[i+1][j]<grid[i][j]) m=max(solve(i+1, j)+1, m);
    if (j<c-1 and grid[i][j+1]<grid[i][j]) m=max(solve(i, j+1)+1, m);
    return dp[i][j]=m;
}

int main()
{
    int n;
    cin>>n;
    while (n--) {
        string name;
        cin>>name>>r>>c;
        memset(dp, -1, sizeof dp);
        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++)
                cin>>grid[i][j];
        int ans=0;
        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++)
                ans=max(solve(i, j), ans);
        cout<<name<<": "<<ans+1<<endl;
    }
    return 0;
}
