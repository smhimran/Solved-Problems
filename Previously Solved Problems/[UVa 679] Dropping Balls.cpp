#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int l, trash, D, I;
	cin>>l;
	while (l--) {
	    cin>>D>>I;
	    int P=1;
	    for (int j=0; j<D-1; j++) {
	        P= (I%2==0)? 2*P+1 : 2*P;
	        I=(I+1)/2;
	    }
	    cout<<P<<endl;
	}
	cin>>trash;
	return 0;
}
