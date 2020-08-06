#include<bits/stdc++.h>
using namespace std;

string add(string a, string b)
{
    string res="";
    if (a.length()>b.length())
        swap(a, b);
    int n1=a.length(), n2=b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry=0, sum=0;
    for (int i=0; i<n1; i++) {
        sum=(a[i]-'0')+(b[i]-'0')+carry;
        carry=sum/10;
        sum%=10;
        res.push_back(sum+'0');
    }
    for (int i=n1; i<n2; i++) {
        sum=(b[i]-'0')+carry;
        carry=sum/10;
        sum%=10;
        res.push_back(sum+'0');
    }
    if (carry)
        res.push_back(carry+'0');
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string in, sum="";
    while (cin>>in and in!="0") {
        sum=add(sum, in);
    }
    cout<<sum<<endl;
    return 0;
}
