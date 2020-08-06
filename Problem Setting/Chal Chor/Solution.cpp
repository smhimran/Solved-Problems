#include<bits/stdc++.h>
using namespace std;


int main()
{
	#ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
   
   	int t, n, ca=1;
   	scanf("%d %d", &t, &n);
    int a[n+1];
    for (int i=0; i<n; i++)
      scanf("%d", a+i);
   	while (t--) {
   		int x;
      scanf("%d", &x);
      int ans = -1, l=0, r=n-1, mid;
      while (l<=r) {
        mid=(l+r)/2;
        if (a[mid]==x) {
          ans=mid+1;
          break;
        }
        else if (a[mid]>x)
          l=mid+1;
        else
          r=mid-1;
      }
      if (ans==-1)
        printf("Chal-Chor #%d: Wrong information! No such house.\n", ca++);
      else 
        printf("Chal-Chor #%d: %d\n", ca++, ans);
   	}
   
    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
	return 0;
}