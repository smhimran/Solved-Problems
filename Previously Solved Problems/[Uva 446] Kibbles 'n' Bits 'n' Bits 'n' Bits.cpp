#include<bits/stdc++.h>
using namespace std;

string Bin(int n)
{
    string res="";
    for (int i=12; i>=0; i--) {
        int x=n>>i;
        if (x&1)
            res+="1";
        else
            res+="0";
    }
    //for (int i=res.size(), )
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, ans=0;
        char c;
        scanf("%X %c %X", &a, &c, &b);
        if (c=='+')
            ans=a+b;
        else if (c=='-')
            ans=a-b;
        string x=Bin(a);
        string y=Bin(b);
        cout<<x<<" "<<c<<" "<<y;
        printf(" = %d\n", ans);
    }
    return 0;
}
