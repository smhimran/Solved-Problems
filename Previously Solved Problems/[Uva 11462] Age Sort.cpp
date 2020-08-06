#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) && n) {
        int a[n];
        for (int i=0; i<n; i++)
            scanf("%d", a+i);
        sort(a, a+n);
        for (int i=0; i<n; i++) {
            if (i==0)
                printf("%d", a[i]);
            else
                printf(" %d", a[i]);
        }
        printf("\n");
    }
    return 0;
}
