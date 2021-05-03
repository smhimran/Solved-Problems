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

/*By Arg_007*/
struct FindHash{
    LL b1 = 129, b2 = 371 ;
    vector <LL> bp1 , bp2 ;
    vector <LL> h1 , h2 ;
    string s ;
    LL sz ;
 
    LL mod1 = 998244353LL , mod2 = 1000000009LL ;
 
    void init( string _s)
    {
        bp1.clear() ;
        bp2.clear() ;
        h1.clear() ; h2.clear() ;
 
        s = _s ;
        sz = s.size() ;
 
        bp1.PB(1) ; bp2.PB(1) ;
 
        for(int i=1 ; i < sz+2 ; i++)
        {
            bp1.PB( (1LL*bp1.back()*b1)%mod1 ) ;
            bp2.PB( (1LL*bp2.back()*b2)%mod2 ) ;
        }
 
        h1.PB(s[0]-'a' + 1) ; h2.PB(s[0]-'a' + 1) ;
 
        for(int i=1 ; i<sz ; i++)
        {
            h1.PB( (1LL*h1.back()*b1 + s[i]-'a' + 1) % mod1 ) ;
            h2.PB( (1LL*h2.back()*b2 + s[i]-'a' + 1) % mod2 ) ;
        }
    }
 
    pair<int,int> Get(int i, int j)
    {
        pair<int,int> res = MP( h1[j],h2[j] ) ;
        if(i>0) res=MP((res.first-1LL*h1[i-1]*bp1[j-i+1])%mod1,(res.second-1LL*h2[i-1]*bp2[j-i+1])%mod2);
        res = MP((res.first%mod1+mod1)%mod1,(res.second%mod2+mod2)%mod2);
        return res ;
    }
 
}f1, f2, f3;
 
inline bool isPal(int l,int r,int n) {return f1.Get(l, r)==f2.Get(n-r-1, n-l-1);}

LL mod (LL b, LL p, LL m)
{
    if (p==0) return 1;
    if (p%2==0) {
        LL x=mod(b, p/2, m);
        return (x*x)%m;
    }
    else return (b%m * mod(b, p-1, m))%m;
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
  		string s;
  		cin>>s;

  		f1.init(s);
  		reverse(s.begin(), s.end());
  		f2.init(s);

  		LL forward_hash = f1.h1.back();
  		LL reverse_hash = f2.h1.back();
  		LL base = 129;
  		LL n = len(s);

  		cout<<"Case "<<ca++<<":"<<endl;

  		int q;
  		cin>>q;

  		while (q--) {
  			char o, c;
  			int times;
  			string temp = "";
  			cin>>o>>c>>times;
  			for (int i=0; i<times; i++)
  				temp += c;

  			f3.init(temp);
  			LL hash_val = f3.h1.back();

  			if (o == 'L') {
  				LL po = mod(base, n, 998244353LL), bb = mod(base, times, 998244353LL);
  				forward_hash = ((hash_val % 998244353LL * po) % 998244353LL + forward_hash % 998244353LL) % 998244353LL;
  				n++;
  				reverse_hash = ((reverse_hash % 998244353LL * bb) % 998244353LL + hash_val % 998244353LL) % 998244353LL;
  			}

  			else {
  				LL po = mod(base, n, 998244353LL), bb = mod(base, times, 998244353LL);
  				reverse_hash = ((hash_val % 998244353LL * po) % 998244353LL + reverse_hash % 998244353LL) % 998244353LL;
  				n++;
  				forward_hash = ((forward_hash % 998244353LL * bb) % 998244353LL + hash_val % 998244353LL) % 998244353LL;
  			}
  			debug(hash_val, forward_hash, reverse_hash);

  			cout<<(forward_hash == reverse_hash? "Yes":"No")<<endl;
  		}
  	}

    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}