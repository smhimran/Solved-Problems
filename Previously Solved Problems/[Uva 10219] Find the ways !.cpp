#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main() {
    int n, k;
	while (scanf("%d %d", &n, &k)!=EOF) {
        double ans=log10(1);
        if (k>(n/2))
            k=n-k;
        for (int i=0; i<k; i++) {
            ans=ans+log10(n-i);
            ans=ans-log10(1+i);
        }
        int sol=floor(ans)+1;
        printf("%d\n", sol);
    }
	return 0;
}
