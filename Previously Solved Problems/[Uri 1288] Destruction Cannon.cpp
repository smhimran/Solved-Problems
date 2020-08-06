#include<bits/stdc++.h>
using namespace std;
int damage[55], weight[55];
int cap, n;
int dp[55][105];

int solve(int i, int w)
{
    if (i==n) return 0;
    if (dp[i][w]!=-1) return dp[i][w];
    int r=0;
    if (w-weight[i]>=0)
        r=max(r, damage[i]+solve(i+1, w-weight[i]));
    r=max(r, solve(i+1, w));
    return dp[i][w]=r;
}

int main()
{
    int t;
    cin>>t;
    //memset(dp, -1, sizeof dp);
    while (t--) {
        int R;
        cin>>n;
        for (int i=0; i<n; i++) {
            scanf("%d %d", damage+i, weight+i);
        }
        cin>>cap;
        cin>>R;
        memset(dp, -1, sizeof dp);
        if (solve(0,cap)>=R)
            cout<<"Missao completada com sucesso"<<endl;
        else cout<< "Falha na missao"<<endl;
    }
    return 0;
}
