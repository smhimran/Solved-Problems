#include<bits/stdc++.h>
using namespace std;

int n, k;
int coins[102];
int dp[10004];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, ca=1, mod=1e8+7;
    cin>>t;
    while (t--) {
        cin>>n>>k;
        for (int i=0; i<n; i++)
            cin>>coins[i];
        memset(dp, 0, sizeof dp);
        dp[0]=1;
        for (int i=0; i<n; i++) {
            for (int j=coins[i]; j<=k; j++) {
                dp[j]+=dp[j-coins[i]];
                dp[j]%=mod;
            }
        }
        cout<<"Case "<<ca++<<": "<<dp[k]<<endl;
    }
    return 0;
}
