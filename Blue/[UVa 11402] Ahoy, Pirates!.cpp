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
#define MAX                 1000007
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

LL tree[6*MAX],arr[6*MAX],lazy[6*MAX];

void buildtree(int node, int b, int e){
    if(b==e){
         tree[node]=arr[e];
         lazy[node] = -1;
         return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)/2;
    buildtree(left,b,mid);
    buildtree(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
    lazy[node] = -1;
}

void clearlazy(int node,int b, int e){
  if (lazy[node] < 0)
    return;
  
  
  if(b!=e){
      int left=node<<1;
      int right =left+1;
      
      if (lazy[node] == 2) {
        if (lazy[left] == 2) 
          lazy[left] = -1;
        
        else if (lazy[left] == -1)
          lazy[left] = 2;
        
        else 
          lazy[left] = !lazy[left];
        
        if (lazy[right] == 2) 
          lazy[right] = -1;
        
        else if (lazy[right] == -1)
          lazy[right] = 2;
        
        else 
          lazy[right] = !lazy[right];
      }
      
      else {
        lazy[left] = lazy[right] = lazy[node]; 
      }
  }
  
  if (lazy[node] == 2) {
    int siz = e - b + 1;
    
    tree[node] = siz - tree[node];
  }
  
  else if (lazy[node] == 0) {
    tree[node] = 0;
  }
  
  else if (lazy[node] == 1) {
    int siz = e - b + 1;
    
    tree[node] = siz;
  }
  
  lazy[node]=-1;
}

void update(int node, int b, int e, int i, int j, int x){
    clearlazy(node,b,e);
    if (i>e||j<b)
        return;
    if (b>=i&&e<=j)
    {
        lazy[node]=x;
        clearlazy(node,b,e);
        return;
    }
    int left = node<<1;
    int right = left + 1;
    int mid = (b + e) / 2;
    update(left, b, mid, i, j, x);
    update(right, mid + 1, e, i, j, x);
    
    tree[node]=tree[left]+tree[right];
}

int query(int node, int b, int e, int i, int j){
    clearlazy(node,b,e);
    if (i > e || j < b)
        return 0;

    if (b >= i && e <= j)
        return tree[node];

    int Left = node<<1;
    int Right = Left + 1;
    int mid = (b + e)/2;

    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}

int main()
{
    // FastIO;
    #ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
    
    int t, ca=1;
    cin>>t;
    while (t--) {
    
      int m;
      cin>>m;
      
      string input = "";
      
      while (m--) {
        int times;
        string s;
        cin>>times>>s;
        
        while (times--)
          input += s;
      }
      
      int n = len(input);
      
      for (int i=1; i<=n; i++)
        arr[i] = input[i - 1] - '0';
      
      buildtree(1, 1, n);
      
      cout<<"Case "<<ca++<<":"<<endl;
     
      int q, qc = 1;
      cin>>q;
      
      while (q--) {
        string type;
        int a, b;
        
        cin>>type>>a>>b;
        
        a++; b++;
        
        if (type == "F")
          update(1, 1, n, a, b, 1);
        
        else if (type == "E")
          update(1, 1, n, a, b, 0);
        
        else if (type == "I")
          update(1, 1, n, a, b, 2);
        
        else 
          cout<<"Q"<<qc++<<": "<<query(1, 1, n, a, b)<<endl;
      }
      
    }

    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}