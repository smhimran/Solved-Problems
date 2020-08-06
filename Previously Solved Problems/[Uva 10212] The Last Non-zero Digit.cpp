#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, m;
    while (cin>>n>>m) {
        if (m==0) {
            cout<<1<<endl;
            continue;
        }
        ll ans=1, k=n-m+1;
        for (int i=n; i>=k; i--) {
            ans*=i;
            while (ans%10==0)
                ans/=10;
            ans%=1000000000;
        }
        cout<<ans%10<<endl;
    }
    return 0;
}
