#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, ca=1;
    cin>>t;
    while (t--) {
        int n, k, p;
        cin>>n>>k>>p;
        int z=k;
        for (int i=0; i<p; i++) {
            z++;
            if (z>n) z=1;
        }
        printf("Case %d: %d\n", ca++, z);
    }
    return 0;
}
