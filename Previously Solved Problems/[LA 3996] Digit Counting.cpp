#include<bits/stdc++.h>
using namespace std;
int mark[10];

int main()
{
    int t;
    cin>>t;
    while (t--) {
        int n, x;
        cin>>n;
        memset(mark, 0, sizeof mark);
        string s="";
        for (int i=1; i<=n; i++) {
            s+=std::to_string(i);
        }
        for (int i=0; s[i]; i++) {
            x=s[i]-'0';
            mark[x]++;
        }
        for (int i=0; i<10; i++) {
            cout<<mark[i];
            if (i!=9) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
