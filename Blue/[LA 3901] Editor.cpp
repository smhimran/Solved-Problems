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


// By sgtlaugh

const int PRIMES[] = {2147462393, 2147462419, 2147462587, 2147462633, 2147462747, 2147463167, 2147463203, 2147463569, 2147463727, 2147463863, 2147464211, 2147464549, 2147464751, 2147465153, 2147465563, 2147465599, 2147465743, 2147465953, 2147466457, 2147466463, 2147466521, 2147466721, 2147467009, 2147467057, 2147467067, 2147467261, 2147467379, 2147467463, 2147467669, 2147467747, 2147468003, 2147468317, 2147468591, 2147468651, 2147468779, 2147468801, 2147469017, 2147469041, 2147469173, 2147469229, 2147469593, 2147469881, 2147469983, 2147470027, 2147470081, 2147470177, 2147470673, 2147470823, 2147471057, 2147471327, 2147471581, 2147472137, 2147472161, 2147472689, 2147472697, 2147472863, 2147473151, 2147473369, 2147473733, 2147473891, 2147473963, 2147474279, 2147474921, 2147474929, 2147475107, 2147475221, 2147475347, 2147475397, 2147475971, 2147476739, 2147476769, 2147476789, 2147476927, 2147477063, 2147477107, 2147477249, 2147477807, 2147477933, 2147478017, 2147478521, 2147478563, 2147478649, 2147479447, 2147479589, 2147480707, 2147480837, 2147480927, 2147480971, 2147481263, 2147481311, 2147481337, 2147481367, 2147481997, 2147482021, 2147482063, 2147482081, 2147482343, 2147482591, 2147483069, 2147483123};

long long basemod[5];

void init(){ /// use init only once at the start of the code in the main function before declaring the hash (you can use init at start of multiple test case but do not use init more than once for each test case)
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    srand(seed);  /// to avoid getting hacked in CF, comment this line for easier debugging
    int q_len = (sizeof(PRIMES) / sizeof(PRIMES[0])) / 4;
    basemod[0] = PRIMES[rand() % q_len];
    basemod[1] = PRIMES[rand() % q_len + q_len];
    basemod[2] = PRIMES[rand() % q_len + 2 * q_len];
    basemod[3] = PRIMES[rand() % q_len + 3 * q_len];
}

struct SingleHash{
    long long base, mod;
    int len;
    vector <int> basepow, f_hash, r_hash;

    SingleHash() {}

    SingleHash(string str, long long base, long long mod): base(base), mod(mod){
        len = len(str);
        basepow.resize(len + 3, 1), f_hash.resize(len + 3, 0), r_hash.resize(len + 3, 0);

        for (int i = 1; i <= len; i++){
            basepow[i] = basepow[i - 1] * base % mod;
            f_hash[i] = (f_hash[i - 1] * base + str[i - 1] + 1007) % mod;
        }

        for (int i = len; i >= 1; i--){
            r_hash[i] = (r_hash[i + 1] * base + str[i - 1] + 1007) % mod;
        }
    }

    inline int forward_hash(int l, int r){
        int h = f_hash[r + 1] - ((long long)basepow[r - l + 1] * f_hash[l] % mod);
        
        return h < 0 ? h + mod : h;
    }

    inline int reverse_hash(int l, int r){
        int h = r_hash[l + 1] - ((long long)basepow[r - l + 1] * r_hash[r + 2] % mod);
        
        return h < 0 ? h + mod : h;
    }

    inline int insert_update(int ind, char c){ //This won’t change the value in hashing template. It will just give the modified value for a single query
        long long l = ((f_hash[ind]*base)%mod+(c+1007))%mod;
        long long r = forward_hash(ind,len-1);

        return ((l*basepow[len-ind])%mod+r)%mod;
    }

    inline int erase_update(int ind){//This won’t change the value in hashing template. It will just give the modified value for a single query
        long long l=f_hash[ind];

        long long r=(ind+1<len)? forward_hash(ind+1,len-1):0LL;

        return ((l*basepow[len-ind-1])%mod+r)%mod;
    }

    inline int replace_update(int ind, char c){//This won’t change the value in hashing template. It will just give the modified value for a single query
        long long l = ((f_hash[ind]*base)%mod+(c+1007))%mod;

        if(ind+1<len) l=(l*basepow[len-ind-1])%mod;

        long long r = (ind+1<len)? forward_hash(ind+1,len-1):0LL;

        return (l+r)%mod;
    }
};

struct StringHash{
    SingleHash sh1, sh2;

    StringHash() {}

    StringHash(string str){
        int base_1 = basemod[0];
        int mod_1  = basemod[1];
        int base_2 = basemod[2];
        int mod_2  = basemod[3];

        sh1 = SingleHash(str, base_1, mod_1);
        sh2 = SingleHash(str, base_2, mod_2);
    }

    /// returns the hash of the substring from indices l to r (inclusive)
    long long forward_hash(int l, int r){
        return ((long long)sh1.forward_hash(l, r) << 32) ^ sh2.forward_hash(l, r);
    }

    /// returns the hash of the reversed substring from indices l to r (inclusive)
    long long reverse_hash(int l, int r){
        return ((long long)sh1.reverse_hash(l, r) << 32) ^ sh2.reverse_hash(l, r);
    }

    long long insert_update(int ind,char c){
        return ((long long)sh1.insert_update(ind, c) << 32) ^ sh2.insert_update(ind, c);
    }

    long long erase_update(int ind){
        return ((long long)sh1.erase_update(ind) << 32) ^ sh2.erase_update(ind);
    }

    long long replace_update(int ind,char c){
        return ((long long)sh1.replace_update(ind, c) << 32) ^ sh2.replace_update(ind, c);

    }

    bool isPalin(int l, int r){ return (forward_hash(l,r)==reverse_hash(l,r));}
};



int main()
{
    // FastIO;
    #ifdef WOLF
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
    
    int t, ca = 1;
    cin>>t;

    while (t--) {

    	string s;
    	cin>>s;

    	int ans = -1, n = len(s);

    	for (int i=0; i<n; i++) {
    		for (int j=i + 1; j<n; j++) {

    			if (j + ans >= n)
    				break;
    			
    			int k = 0;

    			for (k=0; k<n; k++)
    				if (s[i + k] != s[j + k])
    					break;

    			ans = max(ans, k);
    		}
    	}

    	cout<<ans<<endl;
    }

    END:
    #ifdef WOLF
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}