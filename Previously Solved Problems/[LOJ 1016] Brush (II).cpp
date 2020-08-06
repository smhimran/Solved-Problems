#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, ca=1;
    scanf("%d", &t);
    while (t--) {
        int n, w;
        scanf("%d %d", &n, &w);
        int x[n], y[n];
        for (int i=0; i<n; i++)
            scanf("%d %d", x+i, y+i);
        sort(y, y+n);
        int ans=1;
        int i=0, j=1;
        while (i<n) {
            while (j<n && (y[j]-y[i])<=w)
                j++;
            if (j>=n) break;
            i=j;
            ans++;
        }
        printf("Case %d: %d\n", ca++, ans);
    }
    return 0;
}
