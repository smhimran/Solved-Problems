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
#define MIN                 -100007
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

void buildtree(LL node, LL b, LL e){
    if(b==e){
	    tree[node]=arr[e];
	    return;
    }
    LL left=node<<1;
    LL right=left+1;
    LL mid=(b+e)/2;
    buildtree(left,b,mid);
    buildtree(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

void clearlazy(LL node,LL b, LL e){
	if (lazy[node] != -1)
	    tree[node]=(e-b+1)*lazy[node];
    if(b!=e and lazy[node] != -1) {
        LL left=node<<1;
        LL right =left+1;
        lazy[left]=lazy[node];
        lazy[right]=lazy[node];
    }
    lazy[node]=-1;
}

void update(LL node, LL b, LL e, LL i, LL j, LL x){
    clearlazy(node,b,e);
    if (i>e||j<b)
        return;
    if (b>=i&&e<=j)
    {
        lazy[node]=x;
        tree[node] = (e-b+1)*x;
        clearlazy(node,b,e);
        return;
    }
    LL Left = node<<1;
    LL Right = Left + 1;
    LL mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node]= tree[Left]+ tree[Right];
}

LL query(LL node, LL b, LL e, LL i, LL j){
    clearlazy(node,b,e);
    if (i > e || j < b)
        return 0;

    if (b >= i && e <= j)
        return tree[node];

    LL Left = node<<1;
    LL Right = Left + 1;
    LL mid = (b + e)/2;

    LL p1 = query(Left, b, mid, i, j);
    LL p2 = query(Right, mid + 1, e, i, j);
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
  	scanf("%d", &t);
  	while (t--) {
  	
  		int n, q;
  		scanf("%d %d", &n, &q);
  		
  		memset(arr, 0, sizeof arr);
  		memset(lazy, -1, sizeof lazy);
  		
  		buildtree(1, 1, n);
  		
  		printf("Case %d:\n", ca++);
  		
  		while (q--) {
  			int op, i, j, v;
  			scanf("%d", &op);
  			
  			
  			if (op == 1) {
  				scanf("%d %d %d", &i, &j, &v);
  				
  				i++;
  				j++;
  				
  				update(1, 1, n, i, j, v);
  			}
  			
  			else {
  				scanf("%d %d", &i, &j);
  			// debug(op);
  				
  				i++;
  				j++;
  				
  				LL sum = query(1, 1, n, i, j);
  				
  				LL num = j - i + 1;
  				
  				LL gcd = GCD(sum, num);
  				// debug(sum, num, gcd);
  				
  				sum /= gcd;
  				num /= gcd;
  				
  				if (sum == 0)
  					printf("0\n");
  				
  				else if (num == 1)
  					printf("%lld\n", sum);
  				
  				else 
  					printf("%lld/%lld\n", sum, num);
  			}
  		}
  	}

    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}