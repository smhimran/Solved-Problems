#include<bits/stdc++.h>
using namespace std;

int gcdE(int a, int b, int *x, int *y)
{
    if (a==0) {
        *x=0;
        *y=1;
        return b;
    }
    int x1, y1;
    int gcd=gcdE(b%a, a, &x1, &y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return gcd;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen ( "in.txt", "r", stdin );
        freopen ( "out.txt", "w", stdout );
    #endif
    int a, b;
    while (cin>>a>>b) {
        //if (a>b) swap(a, b);
        int x, y;
        int g=gcdE(a, b, &x, &y);
        if (a==b) {
            x=0;
            y=1;
        }
        //if (x>y) swap(x, y);
        cout<<x<<" "<<y<<" "<<g<<endl;
    }
    return 0;
}
