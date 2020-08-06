#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    int n, k;
    while (scanf("%d %d", &n, &k) , n||k) {
        ll ans=1;
        int x=k, y=n;
        if (k>(n/2))
            k=n-k;
        for (int i=0; i<k; i++) {
            ans*=(n-i);
            ans/=(1+i);
        }
        printf("%d things taken %d at a time is %llu exactly.\n", y, x, ans);
    }
    return 0;
}
