#include <bits/stdc++.h>
using namespace std;
#define ran(a, b)           ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define MAXT                    100
#define MAXN                    30000
#define MX                      100000

bool cmp(int a, int b) {
    return a > b;
}

int main(){
    clock_t tStart = clock();
    freopen("in.txt", "w", stdout);
    srand(time(NULL)); /// resets the random seed
    int t=MAXT;
    printf("%d\n", t);
    while(t--){
        int n=ran(10000, MAXN), x=ran(1, MX), k=0; /// change as you wish
        assert(n>=10000 and n<=MAXN);
        printf("%d %d\n", n, x);
        map<int, bool> mp;
        while (k<n) {
            int z = ran(1, MX);
            assert(z>=10000 and z<=MAXN);
            if (mp[z])
                continue;
            printf("%d", z);
            mp[z] = 1;
            k++;
            if (k<n) printf(" ");
        }
        printf("\n");
    }

    fprintf(stderr, "\n>>Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
