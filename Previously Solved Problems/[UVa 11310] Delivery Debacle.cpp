#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[45];

void precal()
{
    ans[0]=1;
    ans[1]=1;
    ans[2]=5;
    ans[3]=11;
    for (int i=4; i<41; i++)
        ans[i]=ans[i-1]+4*ans[i-2]+2*ans[i-3];
}

int main() {
	precal();
	int t, n;
	cin>>t;
	while (t--) {
	    cin>>n;
	    cout<<ans[n]<<endl;
	}
	return 0;
}
