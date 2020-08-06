#include<bits/stdc++.h>
using namespace std;
#define N 10000
map<char, int>m;
bool prime[N+1];

void sieve ()
{
    memset(prime, true, sizeof prime);
    prime[0]=false;
    for (int i=4; i<=N; i+=2)
        prime[i]=false;
    for (int i=3; i*i<=N; i+=2) {
        if (prime[i]) {
            for (int j=i*i; j<=N; j+=i)
                prime[j]=false;
        }
    }
}

int main()
{
    sieve();
    int k=0;
    for (char i=97; i<123; i++)
        m[i]=++k;
    for (char i=65; i<91; i++)
        m[i]=++k;
    string s;
    while (cin>>s) {
        int sum=0;
        for (int i=0; i<s.size(); i++)
            sum+=m[s[i]];
        if (prime[sum])
            cout<<"It is a prime word."<<endl;
        else
            cout<<"It is not a prime word."<<endl;
    }
    return 0;
}
