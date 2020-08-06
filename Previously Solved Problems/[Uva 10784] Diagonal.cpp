#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
A n-gon has n*(n-3)/2 diagonals. Here n*(n-3)/2 <=N.
or, n*n - 3*n<= N*2
or, n*n -3*n -2*N<=0
Solving this equation gives the answer.
*/

int main()
{
    ll n, ca=1;
    while (cin>>n and n) {
        ll a=1, b=-3, c=(2*n)*(-1);
        long double k=((-b)+sqrt((b*b)-(4*a*c)))/(2*a);
        ll ans=ceil(k);
        cout<<"Case "<<ca++<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
