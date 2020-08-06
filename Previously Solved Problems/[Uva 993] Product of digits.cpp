#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        if (n==1) {
            cout<<1<<endl;
            continue;
        }
        string ans="";
        for (int i=9; i>=2; i--) {
            if (n%i==0) {
                while (n%i==0) {
                    n/=i;
                    ans+=std::to_string(i);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        if (n>1)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
