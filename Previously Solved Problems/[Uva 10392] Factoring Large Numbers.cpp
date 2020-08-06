#include<bits/stdc++.h>
using namespace std;
#define N 1000006
typedef long long ll;
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
    ll n;
    while (scanf("%lld", &n) && n!=-1) {
        int i=0, k=prime.size();
        while (i<k) {
            if (n%prime[i]==0) {
                while (n%prime[i]==0) {
                    printf("    %d\n", prime[i]);
                    n/=prime[i];
                }
            }
            i++;
        }
        if (n!=1)
            printf("    %lld\n", n);
        printf("\n");
    }
    return 0;
}
