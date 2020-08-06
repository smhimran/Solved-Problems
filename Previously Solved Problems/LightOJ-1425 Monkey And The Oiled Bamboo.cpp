#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, ca=1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        long long a[n+1];
        a[0]=0;
        for (int i=1; i<=n; i++) {
            scanf("%lld", &a[i]);
        }
        long long m=-1, k=0;
        for (int i=1; i<=n; i++) {
            k=a[i]-a[i-1];
            if (k>m)
                m=k;
            else if (k==m)
                m++;
        }
        printf("Case %d: %lld\n", ca++, m);
    }
    return 0;
}
