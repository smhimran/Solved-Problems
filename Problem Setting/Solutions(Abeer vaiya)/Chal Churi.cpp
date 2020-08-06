#include<bits/stdc++.h>
using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b) {
  double x= (double)a.first / (double)a.second;
  double y= (double)b.first / (double)b.second;
  return x > y;
}

int main()
{
	#ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
   
   	int t, ca=1;
   	scanf("%d", &t);
   	while (t--) {
   	  int n, m;
      cin>>n>>m;
      pair<int, int> chal[n+1];
      for (int i=0; i<n; i++)
        cin>>chal[i].first>>chal[i].second;
      sort(chal, chal+n, cmp);
      double ans=0.0;
      for (int i=0; i<n; i++) {
        double unit = (double)chal[i].first / (double)chal[i].second;
        int k = min(chal[i].second, m);
        ans += (unit * (double)k);
        m -= k;
      }
      ans *= 100.00;
      printf("%.2lf\n", ans);
   	}
   
    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
	return 0;
}