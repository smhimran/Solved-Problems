#include<bits/stdc++.h>
using namespace std;
int n, tot;
int a[100005];
int ans=1000000009;

void solve (int i, int sum)
{
    if (i==n) {
        int pile1=sum;
        int pile2=tot-sum;
        ans=min(ans, abs(pile1-pile2));
        return;
    }
    solve(i+1, sum+a[i]);
    solve(i+1, sum);
}

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", a+i);
        tot+=a[i];
    }
    solve(0, 0);
    printf("%d\n", ans);
    return 0;
}
