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
#define BSRC          binary_search
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

class point
{
public:
    long double x, y;
    point(long double x, long double y) {
        this->x= x;
        this->y= y;
    }
    bool operator<(const point& a) { return (x==a.x)? y<a.y : x<a.x ;}
};


vector<point> v;

long double area(long double x1, long double y1, long double x2, long double y2, long double x3, long double y3) 
{ 
   return ((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 
  
/* A function to check whether point P(x, y) lies inside the triangle formed  
   by A(x1, y1), B(x2, y2) and C(x3, y3) */ 
bool isInside(long double x1, long double y1, long double x2, long double y2, long double x3, long double y3, long double x, long double y) 
{    
   /* Calculate area of triangle ABC */
   long double A = abs(area (x1, y1, x2, y2, x3, y3)); 
  
   /* Calculate area of triangle PBC */   
   long double A1 = abs(area (x, y, x2, y2, x3, y3)); 
  
   /* Calculate area of triangle PAC */   
   long double A2 = abs(area (x1, y1, x, y, x3, y3)); 
  
   /* Calculate area of triangle PAB */    
   long double A3 = abs(area (x1, y1, x2, y2, x, y)); 
    
   /* Check if sum of A1, A2 and A3 is same as A */ 
   return (A == A1 + A2 + A3); 
} 


bool inside(point a) {
    int n=v.size();
    point src=v[0];
    int l=1, r=n-1, mid;
    while(r-l>1) {
        mid=(l+r)>>1;
        if (area(src.x, src.y, v[mid].x, v[mid].y, a.x, a.y) < 0)
            r=mid;
        else
            l=mid;
    }
    return isInside(src.x, src.y, v[l].x, v[l].y, v[r].x, v[r].y, a.x, a.y);
}

int main()
{
    FastIO;
    #ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif

    int t, ca=1;
    cin>>t;
    while (t--) {
        int n, q;
        cin>>n;
        int x, y;
        for (int i=0; i<n; i++) {
            cin>>x>>y;
            v.push_back(point(x, y));
        }
        cin>>q;
        cout<<"Case "<<ca++<<":"<<endl;
        while(q--) {
            cin>>x>>y;
            cout<<(inside(point(x, y))? "y":"n")<<endl;
        }
        v.clear();
    }

    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}