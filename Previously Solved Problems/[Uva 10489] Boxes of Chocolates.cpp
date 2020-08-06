#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--) {
        int n, b, ans=0, temp;
        cin>>n>>b;
        while (b--) {
            int k, x;
            temp=1;
            cin>>k;
            for (int i=0; i<k; i++) {
                cin>>x;
                temp=(temp*x)%n;
            }
            ans=(ans+temp)%n;
        }
        cout<<ans<<endl;
    }
    return 0;
}
