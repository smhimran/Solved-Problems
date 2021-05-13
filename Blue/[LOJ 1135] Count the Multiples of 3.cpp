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
#define MAX                 100007
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

#ifdef WOLF
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

LL tree[6*MAX][5], lazy[6*MAX];

void buildtree(LL node, LL b, LL e){
    if(b==e){
	    tree[node][0]=1;
	    tree[node][1]=0;
	    tree[node][2]=0;

	    return;
    }
    LL left=node<<1;
    LL right=left+1;
    LL mid=(b+e)/2;
    buildtree(left,b,mid);
    buildtree(right,mid+1,e);
    tree[node][0]=tree[left][0]+tree[right][0];
    tree[node][1]=tree[left][1]+tree[right][1];
    tree[node][2]=tree[left][2]+tree[right][2];
}

void clearlazy(LL node,LL b, LL e){
	if (lazy[node] != 0) {
		LL temp = tree[node][0];
		tree[node][0] = tree[node][2];
		tree[node][2] = tree[node][1];
		tree[node][1] = temp;

		if (lazy[node] > 1) {
			temp = tree[node][0];
			tree[node][0] = tree[node][2];
			tree[node][2] = tree[node][1];
			tree[node][1] = temp;
		}
	}
    if(b!=e) {
        LL left=node<<1;
        LL right =left+1;
        lazy[left]=(lazy[node] + lazy[left]) % 3;
        lazy[right]=(lazy[node] + lazy[right]) % 3;
    }
    lazy[node]=0;
}

void update(LL node, LL b, LL e, LL i, LL j){
    clearlazy(node,b,e);
    if (i>e||j<b)
        return;
    if (b>=i&&e<=j) {
        lazy[node]++;
        lazy[node] %= 3;
        clearlazy(node,b,e);
        return;
    }
    LL Left = node<<1;
    LL Right = Left + 1;
    LL mid = (b + e) / 2;
    update(Left, b, mid, i, j);
    update(Right, mid + 1, e, i, j);

    tree[node][0]=tree[Left][0]+tree[Right][0];
    tree[node][1]=tree[Left][1]+tree[Right][1];
    tree[node][2]=tree[Left][2]+tree[Right][2];
}

LL query(LL node, LL b, LL e, LL i, LL j){
    clearlazy(node,b,e);
    if (i > e || j < b)
        return 0;

    if (b >= i && e <= j)
        return tree[node][0];

    LL Left = node<<1;
    LL Right = Left + 1;
    LL mid = (b + e)/2;

    LL p1 = query(Left, b, mid, i, j);
    LL p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}


int main()
{
    FastIO;
    #ifdef WOLF
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
    
  	int t, ca = 1;
  	cin>>t;
  	while (t--) {
  	
  		memset(lazy, 0, sizeof lazy);

  		int n, q;
  		cin>>n>>q;

  		buildtree(1, 1, n);

  		cout<<"Case "<<ca++<<":\n";
  		
  		while (q--) {
  			int type, i, j;
  			cin>>type>>i>>j;

  			if (type == 0) 
  				update(1, 1, n, i + 1, j + 1);

  			else 
  				cout<<query(1, 1, n, i + 1, j + 1)<<endl;
  		}
  	
  	}

    END:
    #ifdef WOLF
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}