#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	while (cin>>s and s[0]!='-') {
	    if (s[0]=='0' and s[1]=='x') {
	        s.erase(s.begin());
	        s.erase(s.begin());
	        int x=stoi(s, nullptr, 16);
	        printf("%d\n", x);
	    }
	    else {
	        int x=stoi(s);
	        printf("0x%X\n", x);
	    }
	}
	return 0;
}
