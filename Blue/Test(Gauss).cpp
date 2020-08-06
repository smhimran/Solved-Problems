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

#define M 50 
  
// Function to print the matrix 
void PrintMatrix(double a[][M], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j <= n; j++)  
          cout << a[i][j] << " "; 
        cout << endl; 
    } 
} 
  
// function to reduce matrix to reduced 
// row echelon form. 
int PerformOperation(double a[][M], int n) 
{ 
    int i, j, k = 0, c, flag = 0, m = 0; 
    double pro = 0; 
      
    // Performing elementary operations 
    for (i = 0; i < n; i++) 
    { 
        if (a[i][i] == 0)  
        { 
            c = 1; 
            while ((i + c) < n && a[i + c][i] == 0)  
                c++;             
            if ((i + c) == n) { 
                flag = 1; 
                break; 
            } 
            for (j = i, k = 0; k <= n; k++)  
                swap(a[j][k], a[j+c][k]); 
        } 
  
        for (j = 0; j < n; j++) { 
              
            // Excluding all i == j 
            if (i != j) { 
                  
                // Converting Matrix to reduced row 
                // echelon form(diagonal matrix) 
                double pro = a[j][i] / a[i][i]; 
  
                for (k = 0; k <= n; k++)                  
                    a[j][k] = a[j][k] - (a[i][k]) * pro;                 
            } 
        } 
    } 
    return flag; 
} 

void PrintResult(double a[][M], int n, int flag) 
{ 
  
    if (flag == 2) {
      int cnt = 0;
      for (int i=0; i<n; i++) {
        if (a[i][i])
            cnt++;
      }
      cout << "Infinitely many solutions containing "<< n-cnt <<" arbitrary constants." << endl;     
    }
    else if (flag == 3)      
      cout << "No Solution." << endl; 
      
      
    // Printing the solution by dividing constants by 
    // their respective diagonal elements 
    else { 
        for (int i = 0; i < n; i++)          
            cout << a[i][n] / a[i][i] << " ";         
    } 
} 
  
// To check whether infinite solutions  
// exists or no solution exists 
int CheckConsistency(double a[][M], int n, int flag) 
{ 
    int i, j; 
    double sum; 
      
    // flag == 2 for infinite solution 
    // flag == 3 for No solution 
    flag = 3; 
    for (i = 0; i < n; i++)  
    { 
        sum = 0; 
        for (j = 0; j < n; j++)         
            sum = sum + a[i][j]; 
        if (sum == a[i][j])  
            flag = 2;         
    } 
    return flag; 
} 

int main()
{
    // FastIO;
    #ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
    
    int m, n;
    cin>>m>>n;
    // M=n+1;
    double a[n][50];
    for (int i=0; i<n; i++)
        for (int j=0; j<=m; j++)
            cin>>a[i][j];
    int flag = 0; 
    PrintMatrix(a, n);
    // Performing Matrix transformation 
    flag = PerformOperation(a, n); 
      
    if (flag == 1)      
        flag = CheckConsistency(a, n, flag);     
    // Printing Solutions(if exist) 
    PrintResult(a, n, flag); 
    
    END:
    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif
    return 0;
}