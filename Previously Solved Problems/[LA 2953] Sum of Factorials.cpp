#include<bits/stdc++.h>
using namespace std;

int fact[21];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    fact[0]=fact[1]=1;
    for (int i=2; i<21; i++)
        fact[i]=i*fact[i-1];
    int n;
    while (cin>>n && n>-1) {
        if (n==0) {
            cout<<"NO"<<endl;
            continue;
        }
        int i=12;
        while (n>=0 && i>=0) {
            if (fact[i]<=n)
                n-=fact[i];
            i--;
        }
        if (n==0)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
