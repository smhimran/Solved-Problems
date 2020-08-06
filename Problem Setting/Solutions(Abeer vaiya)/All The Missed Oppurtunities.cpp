#include<bits/stdc++.h>
using namespace std;

int n, v, value[1005], amount[1005], dp[1005][1005];

int solve(int i, int val) {
  if (i==n)
    return 0;
  int &ret = dp[i][val];
  if (ret!=-1)
    return ret;
  for (int i=0; i<=amount[i]; i++)
    if (val+(value[i]*amount[i])<=v)
      ret = max(ret, (value[i]*amount[i])+solve(i+1, val+(value[i]*amount[i])));
  return ret;
} 

int main()
{
	#ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
   
   	int t, n, ca=1;
   	scanf("%d", &t);
   	while (t--) {
      cin>>n>>v;
      for (int i=0; i<n; i++) 
        cin>>value[i]>>amount[i];
      memset(dp, -1, sizeof dp);
      cout<<solve(0, 0)<<endl;
   	}
   
    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
	return 0;
}