#include<bits/stdc++.h>
using namespace std;

#define inf			int(5e6+9)
#define FastIO              ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

vector<int> v[inf + 1];

bool visited[inf + 1];

int dfs(int n) {
	
	int ret = 0, days = 0;
	
	for (int i=0; i<v[n].size(); i++) {
		if (!visited[v[n][i]]) {
			visited[v[n][i]] = 1;
			ret += (n == 1? 0: days) + 1 + dfs(v[n][i]);
			days = 1;
		}
	}
	
	return ret;
}

void clear(int n) {
	for (int i=0; i<=n; i++) {
		v[i].clear();
		visited[i] = 0;
	}
}

int main()
{
    FastIO;
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
  		
  		
  		for (int i=2; i<=n; i++) {
  			int x;
			cin>>x;

			v[i].push_back(x);
			v[x].push_back(i);
  		}
  		
  		visited[1] = 1;
  		
  		cout<<"Case #"<<ca++<<": "<<dfs(1)<<endl;
  		
  		if (t)
	  		clear(n);
  	}

    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}