#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
	ll n;
	while (cin>>n and n) {
	    ll sum=0, ans=0, x;
	    while (n--) {
	        cin>>x;
	        sum+=x;
	        ans+=ll(abs(sum));
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
