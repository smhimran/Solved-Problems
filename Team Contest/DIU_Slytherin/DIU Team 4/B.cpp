#include <bits/stdc++.h>
using namespace std;


int main() {
	#ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
     
	int t, ca=1;
	cin>>t;
	while (t--) {
		int a, b;
		cin>>a>>b;

		if (a < b)
			cout<<"WeWillEatYou"<<endl;
		else
			cout<<"FunkyMonkeys"<<endl;
	}

	return 0;
}