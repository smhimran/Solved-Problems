#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[55];

ll fib(int n)
{
    if (n==1) return 2;
    if (n==0) return 1;
    if (dp[n]!=0) return dp[n];
    return dp[n]=fib(n-1)+fib(n-2);
}

int main()
{
    int t, ca=1;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        cout<<"Scenario #"<<ca++<<":"<<endl;
        cout<<fib(n)<<endl;
        cout<<endl;
    }
    return 0;
}
