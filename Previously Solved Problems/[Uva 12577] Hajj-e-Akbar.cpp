#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int ca=1;
    while (cin>>s and s!="*") {
        if (s=="Hajj")
            printf("Case %d: Hajj-e-Akbar\n", ca++);
        else if (s=="Umrah")
            printf("Case %d: Hajj-e-Asghar\n", ca++);
    }
    return 0;
}

