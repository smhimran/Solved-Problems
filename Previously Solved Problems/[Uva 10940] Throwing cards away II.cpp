#include<bits/stdc++.h>
using namespace std;
int ans[500005];

void precal()
{
    ans[1]=1;
    ans[2]=2;
    int last=2;
    for (int i=3; i<=500000; i++) {
        if (i<last) last=2;
        ans[i]=last;
        last+=2;
    }
}

int main()
{
    precal();
    int n;
    while (cin>>n && n) {
        cout<<ans[n]<<endl;
    }
    return 0;
}
