#include<bits/stdc++.h>
using namespace std;
int dragon[20004], knight[20004];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
   int n, m;
   while (cin>>n>>m && n && m) {
        for (int i=0; i<n; i++)
            scanf("%d", dragon+i);
        for (int i=0; i<m; i++)
            scanf("%d", knight+i);
        sort(dragon, dragon+n);
        sort(knight, knight+m);
        int i=0, j=0, ans=0;
        while (i<n && j<m) {
            if (dragon[i]<=knight[j]) {
                ans+=knight[j];
                i++;
                j++;
            }
            else j++;
        }
        if (i<n)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n", ans);
   }
   return 0;
}
