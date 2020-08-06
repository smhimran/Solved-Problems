#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        int i=0;
        while (n>=m) {
            n-=(m-1);
            i++;
        }
        if (n==1)
            cout<<i<<endl;
        else
            cout<<"cannot do this"<<endl;
    }
    return 0;
}
