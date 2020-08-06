#include<bits/stdc++.h>
using namespace std;
#define M 1000006
typedef long long ll;
ll tri[M];
int main()
{
    ll k=0;
    tri[3]=0;
    for (int i=4; i<M; i++) {
        k+=(i-2)/2;
        tri[i]=tri[i-1]+k;
    }
    int n;
    while (cin>>n and n>=3) {
        cout<<tri[n]<<endl;
    }
    return 0;
}
