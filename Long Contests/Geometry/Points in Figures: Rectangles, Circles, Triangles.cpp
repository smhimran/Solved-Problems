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
#define sqr(x)				((x) * (x))
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

double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) 
{ 
   return ((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 
  
 
bool isInsideTriangle(double x1, double y1, double x2, double y2, double x3, double y3, long double x, long double y) 
{    

   double A = abs(triangleArea (x1, y1, x2, y2, x3, y3)); 
     
   double A1 = abs(triangleArea (x, y, x2, y2, x3, y3)); 

   double A2 = abs(triangleArea (x1, y1, x, y, x3, y3)); 
    
   double A3 = abs(triangleArea (x1, y1, x2, y2, x, y)); 

   return (fabs(A - (A1 + A2 + A3)) < 1e-5 and (A1 != 0 and A2 != 0 and A3 != 0)); 
} 

bool isInsideRectangle(double x1, double y1, double x2, double y2, double x, double y) {
    double leftX = min(x1, x2), leftY = min(y1, y2);
    double rightX = max(x1, x2), rightY = max(y1, y2);
    
    if (x > leftX and x < rightX and y > leftY and y < rightY) 
        return true;
 
    return false;
}

bool isInsideCircle(double x1, double y1, double r, double x, double y) {
	return sqr(x - x1) + sqr(y - y1) < sqr(r);
}

int main()
{
    // FastIO;
    #ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
    
    char type[15];
    double values[15][10];
    int index = 0; 
    
  	char c;
  	while (cin>>c) {
  		if (c == '*')
  			break;
  		
  		type[index] = c;
  		 
  		if (c == 'r') {
  			for (int i=0; i<4; i++)
  				cin>>values[index][i];
  		}
  		
  		else if (c == 'c') {
  			for (int i=0; i<3; i++)
  				cin>>values[index][i];
  		}
  		
  		else {
  			for (int i=0; i<6; i++)
  				cin>>values[index][i];
  		}
  		
  		index++;
  	}
  	
  	double x, y;
  	int point = 0;
  	
  	while (cin>>x>>y) {
  		if (x==9999.9 and y==9999.9)
  			break;
  		
  		point++;
  		
  		bool inside = 0;
  		
  		for (int i=0; i<index; i++) {
  			if (type[i] == 'r') {
  				if (isInsideRectangle(values[i][0], values[i][1], values[i][2], values[i][3], x, y)) {
  					cout<<"Point "<<point<<" is contained in figure "<<i + 1<<endl;
  					inside = 1;
  				}
  			}
  			
  			else if (type[i] == 't') {
  				if (isInsideTriangle(values[i][0], values[i][1], values[i][2], values[i][3], values[i][4], values[i][5], x, y)) {
  					cout<<"Point "<<point<<" is contained in figure "<<i + 1<<endl;
  					inside = 1;
  				}
  			}
  			
  			else if (type[i] == 'c') {
  				if (isInsideCircle(values[i][0], values[i][1], values[i][2], x, y)) {
  					cout<<"Point "<<point<<" is contained in figure "<<i + 1<<endl;
  					inside = 1;
  				}
  			}
  		}
  		
  		if (!inside)
  			cout<<"Point "<<point<<" is not contained in any figure"<<endl;
  	}
  		
  		
    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}