#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>L, R;
ll coins[20];

void sub (int sum, int s, int e, vector<ll> &v)
{
    if (s==e) {
        v.push_back(sum);
        return;
    }
    for (int i=0; i<=2; i++)
        sub(sum+coins[s]*i, s+1, e, v);
}

int main()
{
    int t, ca=1;
    cin>>t;
    while (t--) {
        ll n, k;
        cin>>n>>k;
        for (int i=0; i<n; i++)
            scanf("%lld", coins+i);
        L.clear(); R.clear();
        ll mid=n>>1;
        sub(0, 0, mid, L);
        sub(0, mid, n, R);
        sort(L.begin(), L.end());
        int l=R.size();
        int i=0;
        for (i=0; i<l; i++) {
            int z=k-R[i];
            if (binary_search(L.begin(), L.end(), z))
                break;
        }
        cout<<"Case "<<ca++<<": ";
        if (i==l)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}
