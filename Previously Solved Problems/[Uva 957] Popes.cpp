#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k, n, x;
    while (cin>>k) {
        cin>>n;
        vector<int>v;
        for (int i=0; i<n; i++) {
            cin>>x;
            v.push_back(x);
        }
        int ans=0, f=0, l=0;
        for (int i=0; i<n; i++) {
            int u=upper_bound(v.begin(), v.end(), v[i]+k-1)-v.begin();
            if (u-i >ans) {
                ans=u-i;
                f=v[i];
                l=v[u-1];
            }
        }
        cout<<ans<<" "<<f<<" "<<l<<endl;
    }
    return 0;
}
