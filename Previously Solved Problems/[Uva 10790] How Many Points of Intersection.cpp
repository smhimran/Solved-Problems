#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, ca=1;
    while (scanf("%lld %lld", &a, &b), a||b) {
        printf("Case %lld: %lld\n", ca++, ((a*(a-1)/2)*(b*(b-1)/2)));
    }
    return 0;
}
