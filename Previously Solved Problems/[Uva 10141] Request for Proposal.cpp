#include<bits/stdc++.h>
using namespace std;
#define inf 10000007
int main()
{
    int n, p, t=1;
    while (cin>>n>>p) {
        if (n==0 and p==0) break;
        string bs, bS, prop, ans;
        double price, bp=inf;
        int req, best=0;
        for (int i=0; i<n; i++) {
            getchar();
            getline(cin, bs);
        }
        for (int i=0; i<p; i++) {
            //getchar();
            getline(cin, prop);
            cin>>price>>req;
            if (req>best) {
                best=req;
                ans=prop;
                bp=price;
            }
            else if (req==best) {
                if (price<bp) {
                    ans=prop;
                    bp=price;
                }
            }
            for (int i=0; i<req; i++) {
                getchar();
                getline(cin, bS);
            }
        }
        if (t>1) cout<<endl;
        cout<<"RFP #"<<t++<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
