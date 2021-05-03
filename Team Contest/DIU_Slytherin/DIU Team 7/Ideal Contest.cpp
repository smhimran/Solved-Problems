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

bool solved[355][35];
int rankPosition[355], solveCount[355], teamsSolved[35], lastSolved[35];

double instable[35];

int main()
{
    FastIO;
    #ifdef HOME
     clock_t Start=clock();
    #endif
     
     freopen("ideal.in", "r", stdin);
     freopen("ideal.out", "w", stdout);
    
  	string s;
  	while (true) {
  		getline(cin, s);
  		
  		// Checking if this is the header I want
  		stringstream ss(s);
  		string x;
  		ss>>x;
  		if (x == "Team")
  			break;
  	}
  	
  	reverse(s.begin(), s.end());
  	
  	stringstream ss(s);
  	
  	string x;
  	
  	// Trash input
  	ss>>x;
  	ss>>x;
  	ss>>x;
  	
  	// Getting the number of problems
  	ss>>x;
  	
  	int problems = x[0] - 'A';
  	problems++;
  	
  	getline(cin, s);
  	
  	int team = 1;
  	
  	// Getting all team solve details
  	
  	while (getline(cin, s)) {
  		
  		int r, timeTaken, cnt;
  		
  		reverse(s.begin(), s.end());
  		
  		stringstream strs(s);
  		
  		// Getting the rank of current team
  		
  		strs>>x;
  		
  		reverse(x.begin(), x.end());
  		
  		r = stoi(x);
  		
  		rankPosition[team] = r;
  		
  		// Trash input
  		strs>>x;
  		
  		// Getting solve count of a team;
  		strs>>x;
  		
  		reverse(x.begin(), x.end());
  		
  		cnt = stoi(x);
  		
  		solveCount[team] = cnt;
  		
  		// Marking problems solved by this team
  		
  		for (int i=problems; i>=1; i--) {
  			strs>>x;
  			reverse(x.begin(), x.end());
  			
  			if (x[0] == '+')
  				solved[team][i] = 1;
  		}
  		
  		team++;
  	}
  	
  	// for (int i=1; i<team; i++) {
  	// 	for (int j=1; j<=problems; j++)
  	// 		cout<<solved[i][j]<< ' ';
  	// 	cout<<endl;
  	// }
  	
  	int teams = team - 1;
  	
  	double instability = 0, vainness = 0, oversimplification = 0, evenness = 0, unsolvability = 0;
  	
  	for (int i=teams; i>=1; i--) {
  		if (solveCount[i] == 0) {
  			vainness += (1.0 / double(teams));
  			continue;
  		}
  		
  		if (solveCount[i] == problems) 
  			oversimplification += (1.0 / double(teams));
  		
  		if (i < teams and (solveCount[i] - solveCount[i+1]) > 1) {
  			double diff = solveCount[i] - solveCount[i + 1];
  			
  			diff--;
  			
  			evenness += diff / double(problems);
  		}
  		
  		for (int j=1; j<=problems; j++) {
  			if (solved[i][j]) {
				if (lastSolved[j] == 0) 
	  				lastSolved[j] = i;
	  			
	  			teamsSolved[j]++;
  			}
  		}
  	}
  	
  	for (int i=1; i<=problems; i++) {
  		if (teamsSolved[i] == 0) {
  			unsolvability += (1.0 / double(problems));
  		}
  		
  		int last = lastSolved[i];
  		
  		for (int j=last - 1; j>=1; j--) {
  			if (last != j and rankPosition[j] < rankPosition[last]) {
  				if (!solved[j][i]) {
  					instable[i] += (1.0 / double(teams));
  				}
  			}
  		}
		instability += instable[i];
  	}
  	
  	instability /= double(problems);
  	
  	double ans = 1.03 * vainness;
  	ans += (3.141 * oversimplification);
  	ans += (2.171 * evenness);
  	ans += (1.414 * unsolvability);
  	ans += instability;
  	
  	cout<< fixed << setprecision(3);
  	
  	cout<<"Vainness = "<<vainness<<endl;
  	cout<<"Oversimplification = "<<oversimplification<<endl;
  	cout<<"Evenness = "<<evenness<<endl;
  	cout<<"Unsolvability = "<<unsolvability<<endl;
  	
  	for (int i=1; i<=problems; i++) {
  		cout<<"Instability "<<i<<" = "<<instable[i]<<endl;
  	}
  	
  	cout<<"Negidealness = "<<ans<<endl;

    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}