#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
#define eps 1e-9
#define unq(c)          (sort(c.begin(), c.end()), c.resize(distance(c.begin(),unique(c.begin(), c.end()))))

// int isprime(int n){
//     if(n < 2) return 0;
//     if(n == 2) return 1;
//     if(!(n & 1)) return 0;
//     int x = sqrt(n) + 1;
//     for(int i = 3; i <= x; i += 2) {
//         if(n % i == 0) return 0;
//     }
//     return 1;
// }

// int dp[1005];


// int solve(int n) {
//     if(n == 0) return 0;

//     if(dp[n] != -1) return dp[n]; 

//     int x = (n + 1) / 2;
    
//     set<int> st;

//     if(x < 2) {
//         int a = 0, b = n-1;
//         st.insert(solve(a) ^ solve(b));
//     }
//     else {
//         for(int i = 2; i <= x; i++) {
//             if(isprime(i)) {

//                 int a = 0, b = n - i;
//                 while(a <= b) {
//                     st.insert(solve(a) ^ solve(b));
//                     a++; b--;
//                 }
//             }
//         }
//     }

//     int ret = 0;
//     for(auto i : st) {
//         if(ret != i) break;
//         ret++;
//     }

//     return dp[n] = ret;
// }

int main() {
    #ifdef HOME
     clock_t Start=clock();
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    #endif
     
    //  memset(dp, -1, sizeof dp);

    // for (int i=1; i<=100; i++) {
    //     if (solve(i) == 0)
    //         cout<<i<<endl;
    // }

     int t, ca=1;
     cin>>t;
     while (t--) {
         int n;
         cin>>n;
         cout<<(n==2 or n==3? "second":"first")<<endl;
     }

    #ifdef HOME
     fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - Start) / CLOCKS_PER_SEC);
    #endif

    return 0;
}