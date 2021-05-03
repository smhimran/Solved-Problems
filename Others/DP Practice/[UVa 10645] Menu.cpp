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

class Dish {
public:
	int cost;
	double value;

	Dish(){}

	Dish(int cost, double value) {
		this -> cost = cost;
		this -> value = value;
	}

	bool operator<(const Dish &a) {
		if (cost == a.cost)
			return value > a.value;
		return cost < a.cost;
	}
} dish[60];

double dp[25][105][55][5];

int path[25][105];

int k, n, m;

double solve(int i, int cost, int prev, int times) {
	if (i == k)
		return 0;

	double &ret = dp[i][cost][prev][times];

	if (ret != -1)
		return ret;


	ret = -inf;


	for (int j=1; j<=n; j++) {
		double ret1 = 0, ret2 = 0;

		if (cost + dish[j].cost <= m) {
			if (prev == j and times == 1)
				ret1 = (dish[j].value / 2.0) + solve(i+1, cost + dish[j].cost, j, times + 1);
			else if (prev != j)
				ret2 = dish[j].value + solve(i+1, cost + dish[j].cost, j, 1);
			// else 
			// 	ret2 = solve(i+1, cost + dish[j].cost, j, 1);

			// debug(ret1, ret2, ret);

			if (ret1 > ret or ret2 > ret) {
				path[i][cost] = j;

				ret = max(ret1, ret2);
			}
		}
	}
	// debug(ret);

	return ret;
}

void print(int i, int now) {
	if (i == k)
		return;

	int p = path[i][now];

	cout<<path[i][now]<<' ';

	print(i+1, now + dish[p].cost);
}

int main()
{
    // FastIO;
    #ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
    
  	while (cin>>k>>n>>m) {
  		if (k==0 and n==0 and m==0)
  			break;

  		for (int i=1; i<=n; i++) {
  			int c;
  			double v;
  			cin>>c>>v;

  			dish[i] = Dish(c, v);
  		}

  		for (int i=0; i<=21; i++) {
  			for (int j=0; j<=101; j++) {
  				for (int k=0; k<=52; k++) {
  					dp[i][j][k][0] = -1;
  					dp[i][j][k][1] = -1;
  					dp[i][j][k][2] = -1;
  				}
  				path[i][j] = 0;
  			}
  		}

  		// sort(dish + 1, dish + n + 1);

  		cout<<solve(0, 0, 0, 0)<<endl;
  		print(0, 0);
  		cout<<endl;
  	}

    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}