#include<bits/stdc++.h>
using namespace std;
int cnt=-1;

int fib(int n)
{
    cnt++;
    if (n==0) return 0;
    if (n==1) return 1;
    return fib(n-1)+fib(n-2);
}

int main()
{
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        cnt=-1;
        int k=fib(n);
        cout<<"fib("<<n<<") = "<<cnt<<" calls = "<<k<<endl;
    }
    return 0;
}
