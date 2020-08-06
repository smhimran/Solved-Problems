#include<bits/stdc++.h>
using namespace std;
int cat[11];

int catalan(int n)
{
    if (n<=1) return 1;
    if (cat[n]!=0) return cat[n];
    int res=0;
    for (int i=0; i<n; i++)
        res+=catalan(i)*catalan(n-i-1);
    return res;
}

int main()
{
    int n, t=0;
    while (cin>>n) {
        if (t) cout<<endl;
        t++;
        cout<<catalan(n)<<endl;
    }
    return 0;
}
