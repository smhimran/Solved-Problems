#include<bits/stdc++.h>
using namespace std;


int main()
{
	#ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
   
   	int n, m, Q, x, y;
    cin>>n>>m>>Q;
    std::vector<int> v[n+1];
    bool visited[n+1];
    for (int i=0; i<m; i++) {
      cin>>x>>y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    for (int i=1; i<=n; i++) 
      sort(v[i].begin(), v[i].end());
    while (Q--) {
      cin>>x;
      queue<int> q;
      memset(visited, 0, sizeof visited);
      q.push(x);
      visited[x]=1;
      while (!q.empty()) {
        int k = q.front();
        q.pop();
        cout<<k<<" ";
        for (auto i: v[k]) {
          if (!visited[i]) {
            q.push(i);
            visited[i]=1;
          }
        }
      }
      cout<<endl;
    }
   
    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
	return 0;
}