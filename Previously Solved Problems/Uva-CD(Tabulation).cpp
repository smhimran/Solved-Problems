#include<bits/stdc++.h>
using namespace std;

int main()
{
    int dp[25][20005], songs[25];
    int n, N;
    while (cin>>N) {
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>songs[i];
        for (int i=0; i<=N; i++)
            dp[0][i]=0;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=N; j++) {
                if (songs[i]<=j)
                    dp[i][j]=max(dp[i-1][j], dp[i-1][j-songs[i]]+songs[i]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        //cout<<"sum: "<<dp[n][N]<<endl;
        int res=dp[n][N], k=N;
        vector<int>ans;
        for (int i=n; i>0; i--) {
            if (dp[i][k]!=dp[i-1][k]) {
                ans.push_back(songs[i]);
                k-=songs[i];
            }
        }
        for (int i=ans.size()-1; i>=0; i--)
            cout<<ans[i]<<" ";
        cout<<"sum:"<<res<<endl;
    }
    return 0;
}
