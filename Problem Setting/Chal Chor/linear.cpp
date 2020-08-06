#include<bits/stdc++.h>
using namespace std;


int main()
{
	#ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out2.txt", "w", stdout);
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
      for (int i=0; i<n; i++) {
        if (a[i]==x) {
            ans=i+1;
            break;
        }
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