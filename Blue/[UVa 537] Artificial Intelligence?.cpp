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

double I, U, P;

bool has_I, has_U, has_P;

bool doesItMatter(string s) {
	return (s[0] == 'I' or s[0] == 'U' or s[0] == 'P') and s[1] == '=';
}

void process(string s) {
	double ret = 0.0, prefix = 0;
	
	bool mulPrefix = 0, divPrefix = 0;
	
	if (s.back() == ',' or s.back() == '?' or s.back() == '.')
		s.pop_back();
	
		// debug(s);
	char c = s[0];
	
	if (!isdigit(s.back())) {
		s.pop_back();
		
	}
	
	if (s.back() == 'k') {
		mulPrefix = 1;
		prefix = 1000.00;
		s.pop_back();
	}
	
	else if (s.back() == 'M') {
		mulPrefix = 1;
		prefix = 1000000.00;	
		s.pop_back();
	}
	
	else if (s.back() == 'm') {
		divPrefix = 1;
		prefix = 1000.00;
		s.pop_back();
	}
	
	s.erase(s.begin());
	s.erase(s.begin());
	
	
	ret = stod(s);
	// debug(ret, mulPrefix, divPrefix);
	
	if (mulPrefix) {
		ret *= prefix;
	}
	
	else if (divPrefix)
		ret /= prefix;
	
	if (c == 'I') {
		I = ret;
		has_I = 1;
	}
	
	else if (c == 'U') {
		U = ret;
		has_U = 1;
	}
	
	else if (c == 'P') {
		P = ret;
		has_P = 1;
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
    
  	int t, ca=1;
  	cin>>t;
  	getchar();
  	while (t--) {
  		
  		has_I = has_P = has_U = 0;
  		
  		I = 0, P = 0, U = 0;
  	
  		string s, word;
  		getline(cin, s);
  		
  		stringstream ss(s);
  		
  		while (ss>>word) {
  			if (doesItMatter(word)) {
  				// debug(word);
  				process(word);
  			}
  		}
  		
  		// debug(I, P, U);
  		
  		cout<<"Problem #"<<ca++<<endl;
  		
  		if (has_I and has_U) {
  			P = U * I;
  			cout<<fixed<<setprecision(2)<<"P="<<P<<"W"<<endl;
  		}
  		
  		else if (has_I and has_P) {
  			U = P / I;
  			cout<<fixed<<setprecision(2)<<"U="<<U<<"V"<<endl;
  		}
  		
  		else if (has_P and has_U) {
  			I = P / U;
  			cout<<fixed<<setprecision(2)<<"I="<<I<<"A"<<endl;
  		}
  		
  		cout<<endl;
  	}

    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}