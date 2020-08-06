#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ca=1;
	while (cin>>n) {
	    int a[n];
	    map<int, bool>m;
	    bool flag=true;
	    for (int i=0; i<n; i++) scanf("%d", a+i);
	    if (a[0]<1) flag=false;
	    for (int i=0; i<n; i++) {
	        for (int j=i+1; j<n; j++) {
	            if (a[i]>=a[j]) flag=false;
	            if (m.find(a[j]-a[i])!=m.end()) flag=false;
	            m[a[j]-a[i]]=true;
	        }
	    }
	    printf("Case #%d: It is %sa B2-Sequence.\n\n", ca++, flag? "":"not ");
	}
	return 0;
}
