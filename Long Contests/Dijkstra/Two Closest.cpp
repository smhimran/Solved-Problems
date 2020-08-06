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
#define inf                 int(1e9+9)
#define PI                  acos(-1)
#define BR                  PF("\n")
#define FastIO              ios_base::sync_with_stdio(false)
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
const int mx = int(3e5+5);


std::vector<int> v[mx+1];
int n, m, k, dis[mx+1], parent[mx+1];

bool visited[mx+1];
map<PII, int> cost;

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

void dijkstra(vector<int> source) {
    for (int i=0; i<=n; i++)
        dis[i]=inf;
    priority_queue<node> pq;
    for (auto s: source) {
        dis[s] = 0;
        pq.push(node(s, 0));
        parent[s] = s;
    }
    while (!pq.empty()) {
        node now = pq.top();
        int u=now.x, d=now.d;
        pq.pop();
        if (visited[u])
            continue;
        visited[u]=1;
        for (auto i: v[u]) {
            if (dis[u]+cost[{u, i}] < dis[i]) {
                dis[i] = dis[u]+cost[{u, i}];
                pq.push(node(i, dis[i]));
                parent[i] = parent[u];
            }
        }
    }

}

void clear() {
    memset(dis, 0, sizeof dis);
    // memset(cost, 0, sizeof cost);
    memset(visited, 0, sizeof visited);
    for (int i=0; i<=mx; i++)
        v[i].clear();
    cost.clear();
}


int main()
{
    // FastIO;
    #ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
    

    clear();
    cin>>n>>m>>k;
    std::vector<int> special;
    scanVI(special, k);
    vector<pair<PII, int> > edges;
    int x, y, w;
    while (m--) {
        cin>>x>>y>>w;
        v[x].push_back(y);
        v[y].push_back(x);
        edges.push_back({{x, y}, w});

        cost[{x, y}] = w;
        cost[{y, x}] = w;
    }
    dijkstra(special);
    int ans = inf;
    for (auto i: edges) {
        int a = i.first.first;
        int b = i.first.second;
        w = i.second;
        if (parent[a] != parent[b]) 
            ans = min(ans, dis[a] + w + dis[b]);
    }
    cout<<ans<<endl;
    
    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}