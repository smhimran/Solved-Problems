#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin>>n and n) {
        int x=n%5;
        if (x==0) cout<<"0.00";
        else if (x==1 || x==4) cout<<"0.40";
        else cout<<"0.20";
        cout<<endl;
    }
    return 0;
}
