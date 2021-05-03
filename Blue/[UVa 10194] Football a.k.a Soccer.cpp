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

map<string, int> points, wins, goal_diff, goals, goals_agianst, games_played, ties;

bool isSmaller(string a, string b) {
	for (int i=0; i<len(a); i++)
		a[i] = toupper(a[i]);
	for (int i=0; i<len(b); i++)
		b[i] = toupper(b[i]);

	return a < b;
}

bool cmp(string a, string b) {
	if (points[a] == points[b]) {
		if (wins[a] == wins[b]) {
			if (goal_diff[a] == goal_diff[b]) {
				if (goals[a] == goals[b]) {
					if (games_played[a] == games_played[b]) {
						return isSmaller(a, b);
					}
					return games_played[a] < games_played[b];
				}
				return goals[a] > goals[b];
			}
			return goal_diff[a] > goal_diff[b];
		}
		return wins[a] > wins[b];
	}
	return points[a] > points[b];
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
  		string tournament;
  		getline(cin, tournament);

  		int n;
  		cin>>n;
  		getchar();

  		string team[n+1];
  		for (int i=0; i<n; i++)
  			getline(cin, team[i]);

  		int games;
  		cin>>games;
  		getchar();

  		while (games--) {
  			string s, team1, team2, goal1, goal2;
  			getline(cin, s);
  			int i;
  			for (i=0; i<len(s); i++) {
  				if (s[i] == '#')
  					break;
  				team1 += s[i];
  			}
  			i++;
  			for (; i<len(s); i++) {
  				if (s[i] == '@')
  					break;
  				goal1 += s[i];
  			}
  			i++;
  			for (; i<len(s); i++) {
  				if (s[i] == '#')
  					break;
  				goal2 += s[i];
  			}
  			i++;
  			for (; i<len(s); i++) {
  				team2 += s[i];
  			}

  			int g1 = stoi(goal1), g2 = stoi(goal2);

  			goals[team1] += g1, goals[team2] += g2;
  			goal_diff[team1] += (g1 - g2);
  			goal_diff[team2] += (g2 - g1);

  			goals_agianst[team1] += g2, goals_agianst[team2] += g1;

  			games_played[team1]++;
  			games_played[team2]++;

  			if (g1 > g2) {
  				points[team1] += 3;
  				wins[team1]++;
  			}
  			else if (g1 < g2) {
  				points[team2] += 3;
  				wins[team2]++;
  			}
  			else {
  				points[team1]++;
  				points[team2]++;
  				ties[team1]++;
  				ties[team2]++;
  			}
  		}

  		sort(team, team+n, cmp);

  		cout<<tournament<<endl;

  		for (int i=0; i<n; i++) {
  			string now = team[i];
  			cout<<i+1<<") "<<now<<" "<<points[now]<<"p, "<<games_played[now]<<"g ("<<wins[now]<<"-"<<ties[now]<<"-"<<(games_played[now] - (wins[now] + ties[now]))<<"), "<<goal_diff[now]<<"gd ("<<goals[now]<<"-"<<goals_agianst[now]<<")"<<endl;
  		}

  		if (t)
  			cout<<endl;

  		points.clear();
  		wins.clear();
  		goals.clear();
  		goal_diff.clear();
  		games_played.clear();
  		ties.clear();
  		goals_agianst.clear();
  	}

    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}