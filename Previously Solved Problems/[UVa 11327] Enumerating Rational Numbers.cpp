#include<bits/stdc++.h>
using namespace std;

// - - - - - - Data Types - - - - - - //

typedef long long int LLI;
typedef long int LI;
typedef long long LL;

// - - - - - - Vectors - - - - - - //
typedef vector<int> VI;
typedef vector<LLI> VLLI;
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
typedef set<LLI> SLLI;
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
#define BSRC          		binary_search
#define MAX                 10000007
#define MIN                 -10000007
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

int GCD(int a, int b) { return b == 0 ? a : GCD(b , a % b); }
int LCM(int a, int b) { return a * (b/GCD(a, b)); }
bool CMP(int a, int b) { return a>b; }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - END - - - - - - - - - - - - - - - - - - - - - - - - - //

const int M=200002;
long long pre[M+1];
vector<int> Primes;
void sieve()
{
    bool isPrime[M+1];
    memset(isPrime,true, sizeof isPrime);
    isPrime[0]=isPrime[1]=false;
    for (int i=4; i<=M; i+=2) 
        isPrime[i]=false;
    for (int i=3; i*i<=M; i+=2) {
        if (isPrime[i]) {
            for (int j=i*i; j<=M; j+=2*i)
                isPrime[j]=false;
        }
    }
    Primes.PB(2);
    for (int i=3; i<=M; i+=2) 
        if (isPrime[i])
            Primes.PB(i);
}

int EulerPhi(int n)
{
    long long PF_idx = 0, PF = Primes[PF_idx], ans = n;
    
    while (PF * PF <= n)
    {
        if (n % PF == 0) ans -= ans / PF;
        while (n % PF == 0) n /= PF;
        PF = Primes[++PF_idx];
    }
    
    if (n != 1) ans -= ans / n;
    
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
    
    sieve();
    pre[0]=0, pre[1]=1;
    pre[2]=2;
    for (int i = 2; i < M; ++i)
    {
        int temp = EulerPhi(i);
        pre[i+1] = pre[i] + temp;
    }
    long long n;
    while (cin>>n and n) {
        if (n == 1)
            cout << "0/1\n";
        else if (n == 2)
            cout << "1/1\n";
        else {
            int k=(lower_bound(pre, pre+M, n)-1)-pre;
            n-=pre[k];
            int i=1;
            while (n) {
                if (__gcd(i, k)==1) 
                    n--;
                i++;
            }
            printf("%d/%d\n", i-1, k);
        }
    }

    #ifndef ONLINE_JUDGE
     printf("\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}