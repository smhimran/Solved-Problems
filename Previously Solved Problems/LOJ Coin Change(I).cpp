#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;

ll c[52];
ll taken[52];
ll k, n;
ll dp[52][1008];


ll change (ll i, ll now)
{
    if (now==0)
        return 1;
    if (i==n)
        return 0;
    if (dp[i][now]!=-1) return dp[i][now];
    dp[i][now]=0;
    for(int j=0; j<=taken[i] && now-j*c[i]>=0 ;j++) {
        dp[i][now] += change(i+1, now-j*c[i])%100000007;
        //cout<<dp[i][now];
    }
    return dp[i][now]%100000007;
}

int main()
{
    ll T,cs=0;
    scanf("%lld", &T);
    while(T--)
    {
        memset(dp, -1, sizeof dp);

        scanf("%lld %lld", &n, &k);
        REP(i,n) scanf("%lld", &c[i]);
        REP(i,n) scanf("%lld", &taken[i]);

        printf("Case %lld: %lld\n", ++cs, change(0,k));
    }
    return 0;
}

