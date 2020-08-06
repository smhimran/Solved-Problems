#include<bits/stdc++.h>
using namespace std;

string fib[5006]={""};

string add (string a, string b)
{
    if (a.length()<b.length())
        swap(a, b);
    string ans="";
    int n1=a.length(), n2=b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int sum=0, carry=0;
    for (int i=0; i<n2; i++) {
        sum=(a[i]-'0')+(b[i]-'0')+carry;
        carry=sum/10;
        sum%=10;
        ans.push_back(sum+'0');
    }
    for (int i=n2; i<n1; i++) {
        sum=(a[i]-'0')+carry;
        carry=sum/10;
        sum%=10;
        ans.push_back(sum+'0');
    }
    if (carry)
        ans.push_back(carry+'0');
    reverse(ans.begin(), ans.end());
    return ans;
}

string fibo (int n)
{
    if (n==0) return "0";
    if (n==1 || n==2) return "1";
    if (fib[n]=="")
        fib[n]=add(fibo(n-1), fibo(n-2));
    return fib[n];
}

int main()
{
    int n;
    while (cin>>n) {
        cout<<fibo(n)<<endl;
    }
    return 0;
}
