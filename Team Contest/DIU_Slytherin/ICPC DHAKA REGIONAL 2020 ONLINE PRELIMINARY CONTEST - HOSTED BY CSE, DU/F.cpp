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


vector<LL> primes;

LL ans = 0, high = 0, low = 0,sz = 0;

namespace rho{
    const int MAXP = 10000010;
    const int BASE[] = {2, 450775, 1795265022, 9780504, 28178, 9375, 325};

    long long seq[MAXP+100];
    int primes[MAXP+100], spf[MAXP+100];


    unsigned long long gcd(unsigned long long u, unsigned long long v){
        if (!u) return v;
        if (!v) return u;
        if (u == 1 || v == 1) return 1;

        int shift = __builtin_ctzll(u | v);
        u >>= __builtin_ctzll(u);
        do{
            v >>= __builtin_ctzll(v);
            if (u > v)
                v ^= u ^= v ^= u;
            v = v - u;
        } while (v);

        return u << shift;
    }

    inline long long mod_add(long long x, long long y, long long m){
        return (x += y) < m ? x : x - m;
    }

    inline long long mod_mul(long long x, long long y, long long m){
        long long res = x * y - (long long)((long double)x * y / m + 0.5) * m;
        return res < 0 ? res + m : res;
    }

    inline long long mod_pow(long long x, long long n, long long m){
        long long res = 1 % m;
        for (; n; n >>= 1){
            if (n & 1) res = mod_mul(res, x, m);
            x = mod_mul(x, x, m);
        }

        return res;
    }

    inline bool miller_rabin(long long n){
        if (n <= 2 || (n & 1 ^ 1)) return (n == 2);
        if (n < MAXP) return spf[n] == n;

        long long c, d, s = 0, r = n - 1;
        for (; !(r & 1); r >>= 1, s++) {}

        for (int i = 0; i < 7; i++){
            c = mod_pow(BASE[i], r, n);
            for (int j = 0; j < s; j++){
                d = mod_mul(c, c, n);
                if (d == 1 && c != 1 && c != (n - 1)) return false;
                c = d;
            }

            if (c != 1) return false;
        }
        return true;
    }

    inline void init(){
        int i, j, k, cnt = 0;

        for (i = 2; i < MAXP; i++){
            if (!spf[i]) primes[cnt++] = spf[i] = i;
            for (j = 0, k; (k = (LL)i * primes[j]) < MAXP; j++){
                spf[k] = primes[j];
                if(spf[i] == spf[k]) break;
            }
        }
    }

    long long pollard_rho(long long n){
        while (1){
            long long x = rand() % n, y = x, c = rand() % n, u = 1, v, t = 0;
            long long *px = seq, *py = seq;

            while (1){
                *py++ = y = mod_add(mod_mul(y, y, n), c, n);
                *py++ = y = mod_add(mod_mul(y, y, n), c, n);
                if((x = *px++) == y) break;

                v = u;
                u = mod_mul(u, abs(y - x), n);

                if (!u) return gcd(v, n);
                if (++t == 32){
                    t = 0;
                    if ((u = gcd(u, n)) > 1 && u < n) return u;
                }
            }

            if (t && (u = gcd(u, n)) > 1 && u < n) return u;
        }
    }

    vector <long long> factorize(long long n){
        if (n == 1) return vector <long long>();
        if (miller_rabin(n)) return vector<long long> {n};

        vector <long long> v, w;
        while (n > 1 && n < MAXP){
            v.push_back(spf[n]);
            n /= spf[n];
        }

        if (n >= MAXP) {
            long long x = pollard_rho(n);
            v = factorize(x);
            w = factorize(n / x);
            v.insert(v.end(), w.begin(), w.end());
        }

        sort(v.begin(), v.end());
        return v;
    }
}


void solve(int i, LL num, LL taken) {
  if (i >= primes.size()) 
    return;
  
  LL now = num * primes[i];
  
  if (taken&1) {
    LL cnt = high / now;
    cnt -= low / now;
    ans -= cnt;
  }
  else {
    LL cnt = high / now;
    cnt -= low / now;
    ans += cnt;
  }
  
  solve(i+2, now, taken + 1);
  
  solve(i+1, num, taken);
}

int main()
{
    // FastIO;
    #ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
    
    rho::init();
    
  	int t, ca=1;
  	scanf("%d", &t);
  	while (t--) {
  	
  		LL a, b, c;
  		scanf("%lld %lld %lld", &a, &b, &c);
  		
  		LL d = abs(a - b);
  		
  		primes = rho::factorize(d);
      
      sort(primes.begin(), primes.end());
      
      unique(primes.begin(), primes.end());
      
      ans = b + c - b + 1;
      
      high = b + c;
      low = b - 1;
      
      sz = primes.size();
      
      solve(0, 1, 0);
  		
  		printf("Case %d: %lld\n", ca++, ans - 1);
      
      primes.clear();
  	}

    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}