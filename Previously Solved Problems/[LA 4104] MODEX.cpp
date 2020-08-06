#include<bits/stdc++.h>
using namespace std;

int mod (int b, int p, int m)
{
    if (p==0) return 1;
    if (p%2==0) {
        int x=mod(b, p/2, m);
        return (x*x)%m;
    }
    else return (b%m * mod(b, p-1, m))%m;
}

int main()
{
    int t;
    cin>>t;
    while (t--) {
        int b, p, m;
        cin>>b>>p>>m;
        cout<<mod(b, p, m)<<endl;
    }
    scanf("%*d");
    return 0;
}

