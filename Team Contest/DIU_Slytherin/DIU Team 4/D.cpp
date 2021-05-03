#include <bits/stdc++.h>
using namespace std;

#define unq(c)          (sort(c.begin(), c.end()), c.resize(distance(c.begin(),unique(c.begin(), c.end()))))

int main() {
	#ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
     
	int t, ca=1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);

		int x;
		vector<int> v;

		for (int i=0; i<n; i++) {
			scanf("%d", &x);
			v.push_back(x);
		}

		bool ok = 1;

		sort(v.begin(), v.end());

		for (int i=1; i<n; i++) {
			if ((v[i] - v[i-1]) & 1) 
				ok = 0;
		}

		printf("%s\n", ok? "yes":"no");

	}

	return 0;
}