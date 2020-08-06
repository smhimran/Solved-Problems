#include<bits/stdc++.h>
using namespace std;

typedef long long int  ll;
ll dp[30][2][2][100];
string s;

ll digitdp(ll pos,ll small,ll start,ll sum)
{
    cout<<pos<<endl;
    
    if(pos==s.length())
    {
        return sum;
    }
    ll &ans=dp[pos][small][start][sum];
    if(dp[pos][small][start][sum]!=-1)
        return ans;
    ll lp;
    if(small==1)
        lp=9;
    else
        lp=s[pos]-'0';
    ans=0;
    if(!start)
    {
        for(ll i=0; i<=lp; i++)
        {
            if(i==0)
                ans+=digitdp(pos+1,small | i<s[pos]-'0',0,sum+1);
            else
                ans+=digitdp(pos+1,small | i<s[pos]-'0',0,sum);
        }
    }
    else
    {
        for(ll i=1; i<=lp; i++)
        {
            ans+=digitdp(pos+1,small | i<s[pos]-'0',0,sum);
        }
        ans+=digitdp(pos+1,1,1,0);
    }
    return ans;

}

int main()
{
    ll t,T,i,j;
    string l, r;
    cin>>t;
    for(T=1; T<=t; T++)
    {
        cin>>l>>r;
        s=l;
        cout<<"ok"<<endl;
        memset(dp,-1,sizeof(dp));
        cout<<"k"<<endl;
        ll ans1=digitdp(0,0,1,0)+1;
        cout<<ans1<<endl;
        memset(dp,-1,sizeof(dp));
        s=r;
        ll ans2=digitdp(0,0,1,0)+1;
        // cout<<ans2<<" "<<ans1<<endl;
        cout<<ans2-ans1<<endl;
    }
}