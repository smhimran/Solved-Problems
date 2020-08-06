#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, ca=1;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int c=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='#') {
                if (i-1>=0 && i+1<n)
                    c++;
            }
        }
        cout<<"Case "<<ca++<<": "<<c<<endl;
    }
    return 0;
}
