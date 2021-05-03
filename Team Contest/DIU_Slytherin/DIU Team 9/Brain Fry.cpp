#include<bits/stdc++.h>
using namespace std;

// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

// - - - - - - Data Types - - - - - - //

typedef long int LI;
typedef long long LL;

// - - - - - - Vectors - - - - - - //
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<VI> VVI;

#define scanVI(v, n)        for(int i=0; i<n; i++){ int x; cin >> x; v.PB(x); }
#define scanVLLI(v, n)      for(int i=0; i<n; i++){ LLI x; cin >> x; v.PB(x); }
#define scanVS(v, n)        for(int i=0; i<n; i++){ string x; cin >> x; v.PB(x); }
#define scanVD(v, n)        for(int i=0; i<n; i++){ double x; cin >> x; v.PB(x); }

// - - - - - - Maps - - - - - - //
typedef map<int, int> MII;
typedef map<int, string> MIS;
typedef map<int, char> MIC;
typedef map<string, int> MSI;
typedef map<char, int> MCI;
typedef map<int, VI> MIVI;

// - - - - - - Pairs - - - - - - //
typedef pair<int, int> PII;
typedef pair<string, string> PSS;
typedef pair<char, char> PCC;
typedef pair<int, string> PIS;
typedef pair<int, char> PIC;
typedef pair<string, char> PSC;

// - - - - - - Sets - - - - - - //
typedef set<int> SI;
typedef set<LL> SLL;
typedef set<string> SS;
typedef set<char> SC;
// - - - - - - - - - - - - - - - - - - //

#define PF                  printf
#define SF                  scanf
#define PB                  push_back
#define POP                 pop_back()
#define PP                  prev_permutation
#define NP                  next_permutation
#define MP                  make_pair
#define CLRN(a, b)          memset(a, b, sizeof(a))
#define CLR(a)              memset(a, 0, sizeof(a))
#define ALL(a)              a.begin(), a.end()
#define ALLN(a, n)          (a, a+n)
#define BSRCN(a, n, x)      binary_search(ALLN(a, n), x)
#define BSRC                binary_search
#define MAX                 10000007
#define MIN                 -10000007
#define inf                 int(1e6+9)
#define PI                  acos(-1)
#define BR                  PF("\n")
#define FastIO              ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ()              freopen("input.txt", "r", stdin)
#define WRITE()             freopen("output.txt", "w", stdout)
#define len(a)              a.length()
#define rsort(a)            sort(a.rbegin(), a.rend())
#define pvec(v)             for(auto x: v) cout<<x<<" "

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
/*----------------------Graph Moves----------------*/
int ROW[]={+1,-1,+0,+0};
int COL[]={+0,+0,+1,-1};

int X[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
int Y[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move

int KX[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
int KY[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

// ---------------------DEBUG---------------------//

#ifdef HOME
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cout << name << " = " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names, ',');
        cout.write(names, comma - names) << " = " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif

//------------------------------------------------//

void fastscan(int &number) 
{ 
    bool negative = false; 
    int c; 
  
    number = 0; 
    c = getchar(); 
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 

LL GCD(LL a, LL b) { return b == 0 ? a : GCD(b , a % b); }
int LCM(int a, int b) { return a * (b/GCD(a, b)); }
bool CMP(int a, int b) { return a>b; }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - END - - - - - - - - - - - - - - - - - - - - - - - - - //

int n, m, t;
int dist[500][500], cost[500][500], dis[500];
vector<int> v[500];
bool visited[500], vis[500][120], vis2[500][120];

double probability[500];

double dp[500][120], dp2[500][120];

class node 
{
public:
    int x, d;

    node(int x, int d) {
        this->x=x;
        this->d=d;
    }

    bool operator<(const node &a) const{
        return d > a.d;
    }
};

void dijkstra(int source) {
    for (int i=0; i<=n; i++)
        dis[i]=inf;
    priority_queue<node> pq;
    pq.push(node(source, 0));
    dis[source]=0;
    while (!pq.empty()) {
        node now = pq.top();
        int u=now.x, d=now.d;
        pq.pop();
        if (visited[u])
            continue;
        visited[u]=1;
        for (auto i: v[u]) {
            if (dis[u]+cost[u][i] < dis[i]) {
                dis[i] = dis[u]+cost[u][i];
                pq.push(node(i, dis[i]));
            }
        }
    }
    for (int i=1; i<=n; i++) 
    	dist[source][i] = dis[i];
}

double dfs(int u, int currentTime) {
	double & ret = dp[u][currentTime];
	
	if (vis[u][currentTime])
		return ret;
	
	vis[u][currentTime] = 1;
	ret = probability[u];
	
	if (currentTime >= t) 
		return ret;
	
	double no = 1.0 - probability[u];
	
	int canVisit = 0;
	
	for (auto i: v[u]) {
		if (i != 0)
			canVisit++;
	}
	
	
	if (canVisit == 0) {
		if (u == 0)
			return 0.0;
		
		ret += (1.0 - probability[u]) * dfs(0, currentTime + dis[u]);
		
		return ret;
	}
	
	else {
		double chooseOne = 1.0 / double(canVisit);
		
		for (auto i: v[u]) {
			
			if (i == 0)
				continue;

			ret += (1.0 - probability[u]) * chooseOne * dfs(i, currentTime + cost[u][i]);
		}
		
	}
	
	return ret;
}

double dfs2(int u, int currentTime) {
	double & ret = dp2[u][currentTime];
	
	if (vis2[u][currentTime])
		return ret;
	
	vis2[u][currentTime] = 1;
	ret = probability[u] * dis[u];
	double no = 1.0 - probability[u];
	
	if (currentTime >= t) {
		ret += (no * dis[u]);
		return ret;
	}
	
	
	int canVisit = 0;
	
	for (auto i: v[u]) {
		if (i != 0)
			canVisit++;
	}
	
	
	if (canVisit == 0) {
		if (u == 0)
			return 0.0;
		
		ret += (1.0 - probability[u]) * (dis[u] + dfs2(0, currentTime + dis[u]));
		
		return ret;
	}
	
	else {
		double chooseOne = 1.0 / double(canVisit);
		
		for (auto i: v[u]) {
			
			if (i == 0)
				continue;

			ret += (1.0 - probability[u]) * chooseOne * (cost[u][i] + dfs2(i, currentTime + cost[u][i]));
		}
		
	}
	
	return ret;
}

void clear() {
	for (int i=0; i<500; i++) {
		v[i].clear();
		visited[i] = 0;
		probability[i] = 0.0;
		dis[i] = 0;
	}
	
	memset(dist, 0, sizeof dist);
	memset(cost, 0, sizeof cost);
	memset(vis, 0, sizeof vis);
	memset(vis2, 0, sizeof vis2);
}


int main()
{
    // FastIO;
    #ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
    
  	int T, ca=1;
  	scanf("%d", &T);
  	while (T--) {
  	
  		// int n, m, t;
  		clear();
  		scanf("%d %d %d", &n, &m, &t);
  		
  		for (int i=1; i<=n; i++) 
  			scanf("%lf", probability+i);
  		
  		for (int i=0; i<m; i++) {
  			int x, y, w;
  			scanf("%d %d %d", &x, &y, &w);
  			
  			v[x].push_back(y);
  			v[y].push_back(x);
  			
  			cost[x][y] = w;
  			cost[y][x] = w;
  		}
  		
  		dijkstra(0);
  		
  		printf("Case %d: ", ca++);
  		
  		// for (int i=0; i<=n; i++)
  		// 	cout<<dis[i]<<" ";
  		// // cout<<endl;
  		
  		// cout<<dfs2(0, 0)<<endl;
  		
  		printf("%.5lf %.5lf\n", dfs(0, 0), dfs2(0, 0));
  		
  		
  	}

    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}