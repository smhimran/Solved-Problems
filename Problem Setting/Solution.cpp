#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long double x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
} 

int main()
{
	#ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
   
   	int t, ca=1;
   	cin>>t;
   	while (t--) {
   		int n;
   		cin>>n;
   		int a[n+1], mn = 0;
   		for (int i=0; i<n; i++) {
   			cin>>a[i];
   			mn=max(mn, a[i]);
   		}
   		for (int i=0; i<n; i++) {
   			if (isPerfectSquare(a[i])) {
   				if (a[i]%2==0)
	   				mn = min(mn, a[i]);
   			}
   		}
   		cout<<"Case "<<ca++<<": "<<mn<<endl;
   	}
   
    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
	return 0;
}