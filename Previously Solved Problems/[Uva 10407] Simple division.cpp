#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while (cin>>n && n) {
        vector<int>v;
        do {
            v.push_back(n);
            cin>>n;
        } while (n);
        unique(v.begin(), v.end());
        int k=abs(v[1]-v[0]);
        for (int i=2; i<v.size(); i++) {
            k=__gcd(k, abs(v[i]-v[i-1]));
        }
        cout<<k<<endl;
    }
    return 0;
}
