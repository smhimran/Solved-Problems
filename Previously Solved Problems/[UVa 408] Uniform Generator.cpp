#include<bits/stdc++.h>
using namespace std;

int main()
{
    int step, mod;
    while (cin>>step>>mod) {
        bool k;
        k=(__gcd(step, mod)==1);
        if (mod==1) k=true;
        printf("%10d%10d    %s Choice\n\n", step, mod, k? "Good":"Bad");
    }
    return 0;
}
