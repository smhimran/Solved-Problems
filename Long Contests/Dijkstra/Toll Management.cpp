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
const int mx = int(2e4+5);


std::vector<PII> v[mx+1], v2[mx+1];
int n, m, s, t, p, dis1[mx+1], dis2[mx+1];

bool visited[mx+1];

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
        dis1[i]=inf;
    priority_queue<node> pq;
    pq.push(node(source, 0));
    dis1[source]=0;
    while (!pq.empty()) {
        node now = pq.top();
        int u=now.x, d=now.d;
        pq.pop();
        if (visited[u])
            continue;
        visited[u]=1;
        for (auto i: v[u]) {
            if (d + i.second < dis1[i.first]) {
                dis1[i.first] = d + i.second;
                pq.push(node(i.first, dis1[i.first]));
            }
        }
    }
}

void dijkstra2(int source) {
    for (int i=0; i<=n; i++) 
        dis2[i]=inf;
    priority_queue<node> pq;
    pq.push(node(source, 0));
    dis2[source]=0;
    while (!pq.empty()) {
        node now = pq.top();
        int u=now.x, d=now.d;
        pq.pop();
        if (visited[u])
            continue;
        visited[u]=1;
        for (auto i: v2[u]) {
            if (d + i.second < dis2[i.first]) {
                dis2[i.first] = d + i.second;
                pq.push(node(i.first, dis2[i.first]));
            }
        }
    }
}

void clear() {
    memset(dis1, 0, sizeof dis1);
    memset(dis2, 0, sizeof dis2);
    memset(visited, 0, sizeof visited);
    for (int i=0; i<=mx; i++) {
        v[i].clear();
        v2[i].clear();
    }
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
    cin>>T;
    while (T--) {
        clear();
        cin>>n>>m>>s>>t>>p;
        vector<pair<PII, int> > edges;
        while (m--) {
            int x, y, w;
            cin>>x>>y>>w;
            v[x].push_back({y, w});
            v2[y].push_back({x, w});
            edges.push_back({{x, y}, w});
        }
        dijkstra(s);
        memset(visited, 0, sizeof visited);
        dijkstra2(t);
        int ans = -1;
        for (auto i: edges) {
            int cost = dis1[i.first.first] + i.second + dis2[i.first.second];
            if (cost <= p) {
                ans = max(ans, i.second);
            }
        }
        cout<<"Case "<<ca++<<": "<<ans<<endl;
    }
    
    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}