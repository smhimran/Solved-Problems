#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll a, l, ca=1;
	while (cin>>a>>l) {
	    if (a<0 and l<0) break;
	    ll cnt=1, n=a;
	    while (true) {
	        if (a==1) break;
	        if (a&1) a=(3*a)+1;
	        else a/=2;
	        if (a>l) break;
	        cnt++;
	    }
	    printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", ca++, n, l, cnt);
	}
	return 0;
}
