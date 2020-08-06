#include<stdio.h>
#include<math.h>
long double L[10009];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    int i;
    for (i=1; i<=10000; i++)
        L[i]=log(i);
    int p, q, r, s;
    while (scanf("%d %d %d %d", &p, &q, &r, &s)!=EOF) {
        long double ans=0;
        if (p-q <q) q=p-q;
        if (r-s <s) s=r-s;
        for (i=1; i<=q; i++)
            ans+=L[p-q+i]-L[i];
        for (i=1; i<=s; i++)
            ans+=-L[r-s+i]+L[i];
        printf("%.5lf\n", exp(ans));
    }
    return 0;
}
