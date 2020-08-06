#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll coins[102];
ll dp[102][10004];

ll call(ll i, ll amount)
{
    if (i>=n) {
        if (amount==0) return 1;
        return 0;
    }
    if (dp[i][amount]!=-1) return dp[i][amount];
    dp[i][amount]=0;
    for (ll j=0; j<=k && amount-(j*coins[i])>=0; j++) {
        dp[i][amount]+=call(i+1, amount-(j*coins[i]))%100000007;
    }
    return dp[i][amount]%100000007;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, ca=1;
    cin>>t;
    while (t--) {
        memset(dp, -1, sizeof dp);
        cin>>n>>k;
        for (ll i=0; i<n; i++) {
            cin>>coins[i];
        }
        cout<<"Case "<<ca++<<": "<<call(0, k)<<endl;
    }
    return 0;
}
