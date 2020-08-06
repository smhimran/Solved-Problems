#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, t, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &t, &m);
        int a[m];
        for (int i=0; i<m; i++)
            scanf("%d", a+i);
        int time=0, trip=0;
        sort(a, a+m);
        for (int i=0; i<m;) {
            if (i==0 && (m%n==0)) {
                time=a[n-1]+2*t;
                trip++;
                i=n;
            }
            else if (i==0) {
                time=a[m%n-1]+2*t;
                i=m%n;
                trip++;
            }
            else {
                if (time>=a[i+n-1])
                    time+=2*t;
                else time=a[i+n-1]+2*t;
                trip++;
                i+=n;
            }
        }
        time-=t;
        printf("%d %d\n", time, trip);
    }
    return 0;
}
