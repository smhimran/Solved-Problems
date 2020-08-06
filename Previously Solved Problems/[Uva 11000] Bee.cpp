#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll male[104];
ll female[104];

void solve()
{
    male[0]=0;
    female[0]=1;
    for (int i=1; i<=102; i++) {
        male[i]=female[i-1];
        female[i]=female[i-1]+male[i-1]+1;
    }
}

int main()
{
    solve();
    int n;
    while (cin>>n and n!=-1) {
        cout<<male[n]<<" "<<female[n]<<endl;
    }
    return 0;
}
