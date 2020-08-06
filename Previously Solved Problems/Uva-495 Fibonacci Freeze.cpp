#include<bits/stdc++.h>
using namespace std;

string fibo[5009]={""};

string add(string a, string b)
{
    if (a.length()>b.length())
        swap(a,b);
    string ans="";
    int n1=a.length(), n2=b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry=0, sum=0;
    for (int i=0; i<n1; i++) {
        sum=(a[i]-'0')+(b[i]-'0')+carry;
        ans.push_back(sum%10+'0');
        carry=sum/10;
    }
    for (int i=n1; i<n2; i++) {
        sum=((b[i]-'0')+carry);
        ans.push_back(sum%10+'0');
        carry=sum/10;
    }
    if (carry)
        ans.push_back(carry+'0');
    reverse(ans.begin(), ans.end());
    return ans;
}

string fib (int n)
{
    if (n==0) return "0";
    if (n==1 || n==2) return "1";
    if (fibo[n]=="")
        fibo[n]=add(fib(n-1), fib(n-2));
    return fibo[n];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    while (cin>>n)
        cout<<"The Fibonacci number for "<<n<<" is "<<fib(n)<<endl;
    return 0;
}
