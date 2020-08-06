#include<bits/stdc++.h>
using namespace std;

int selsort (int a[], int n)
{
    int cnt=0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i]>a[j]) {
                swap(a[i], a[i]);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i=0; i<n; i++)
            scanf("%d", a+i);
        int ans=selsort(a, n);
        printf("Optimal train swapping takes %d swaps.\n", ans);
    }
    return 0;
}


