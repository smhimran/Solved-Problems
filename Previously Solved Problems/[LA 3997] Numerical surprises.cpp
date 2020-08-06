#include<bits/stdc++.h>
using namespace std;

int mod (string a, int b)
{
    int res=0;
    for (int i=0; i<a.length(); i++)
        res=(res*10 + (int) a[i]-'0')%b;
    return res;
}

int main()
{
    int t;
    cin>>t;
    while (t--) {
       int n;
       string p;
       cin>>n;
       cin>>p;
       cout<<mod(p, n)<<endl;
    }
    return 0;
}
