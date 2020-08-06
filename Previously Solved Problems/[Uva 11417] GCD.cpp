#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int G(int n)
{
    int g=0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++)
            g+=__gcd(i, j);
    }
    return g;
}

int main()
{
    int n;
    while (cin>>n && n) {
        cout<<G(n)<<endl;
    }
    return 0;
}
