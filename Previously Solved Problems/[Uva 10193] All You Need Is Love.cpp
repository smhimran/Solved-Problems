#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i=len-1;i>=0;i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

int main()
{
    int t, ca=1;
    cin>>t;
    while (t--) {
        string s1,s2;
        cin>>s1>>s2;
        int a=binaryToDecimal(s1), b=binaryToDecimal(s2);
        printf("Pair #%d: ", ca++);
        if (__gcd(a,b)==1)
            cout<<"Love is not all you need!"<<endl;
        else cout<<"All you need is love!"<<endl;
    }
    return 0;
}
