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
  		int n, a, b;
  		cin>>n>>a>>b;
  		if (n == 2) {
  			cout<<a<<" "<<b<<endl;
  			continue;
  		}
  		if (n >= (b-a +1)) {
  			int diff = b-a +1;
  			if (n == diff) {
  				for (int i=a; i<=b; i++)
  					cout<<i<<" ";
  				cout<<endl;
  				continue;
  			}
  			else {
  				vector<int> ans;
  				for (int i=a; i<=b; i++)
  					ans.push_back(i);
  				n -= diff;
  				if (a>1) {
  					for (int i=a-1; i>=1 and n; i--, n--)
  						ans.push_back(i);
  				}
  				if (n) {
  					for (int i=b+1; n; i++, n--)
  						ans.push_back(i);
  				}
  				pvec(ans);
  				cout<<endl;
  				continue;
  			}
  		}
  		else {
  			int diff = b-a, mx = inf;
  			std::vector<int> ans;
  			for (int i=n; i>1; i--) {
  				std::vector<int> v;
  				for (int j=a; j>=1; j--) {
  					int up = (b - j);
  					int down = i-1;
  					// debug(up, down);
  					if (up % down == 0) {
  						int d = up / down;
  						int x = (a - j);
  						if (x % d == 0) {
  							v.push_back(j);
  							int now = j+d;
  							for (int k=2; k<=n; k++) {
  								v.push_back(now);
  								now += d;
  							}
  							if (mx > v.back()) {
  								mx = v.back();
  								ans = v;
  							}
  						}
  					}
  				}
  			}
  			pvec(ans);
  			cout<<endl;
  		}
  	}

    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}