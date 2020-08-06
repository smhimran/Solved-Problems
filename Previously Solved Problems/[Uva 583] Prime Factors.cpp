#include<bits/stdc++.h>
using namespace std;
#define N 10000007
bool isprime[N+1];
vector<int>prime;

void sieve()
{
    memset(isprime, true, sizeof isprime);
    isprime[0]=isprime[1]=false;
    for (int i=4; i<=N; i+=2)
        isprime[i]=false;
    for (int i=3; i<=N/i; i+=2) {
        if (isprime[i]) {
            for (int j=i*i; j<=N; j+=i)
                isprime[j]=false;
        }
    }
    prime.push_back(2);
    for (int i=3; i<=N; i+=2)
        if (isprime[i]) prime.push_back(i);
}

int main()
{
    sieve();
    int n;
    while (cin>>n && n) {
        cout<<n<<" = ";
        bool flag=true;
        if (n<0) {
            cout<<"-1";
            flag=false;
            n*=-1;
        }
        for (int i=0; i<prime.size(); i++) {
            if (prime[i]>n) break;
            if (n%prime[i]==0) {
                while (n%prime[i]==0) {
                    if (flag)  {
                        cout<<prime[i];
                        flag=false;
                    }
                    else
                        cout<<" x "<<prime[i];
                    n/=prime[i];
                }
            }
        }
        if (n>1) {
            if (flag)
                cout<<n;
            else cout<<" x "<<n;
        }
        cout<<endl;
    }
    return 0;
}
