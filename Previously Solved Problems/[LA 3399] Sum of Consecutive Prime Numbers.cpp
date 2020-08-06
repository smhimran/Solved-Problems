#include<bits/stdc++.h>
using namespace std;
#define N 10000
bool prime[N+1];
int primes[1500];
int k;
void sieve ()
{
    prime[0]=prime[1]=1;
    for (int i=4; i<=N; i+=2)
        prime[i]=1;
    for (int i=3; i*i<=N; i+=2) {
        if (prime[i]==0) {
            for (int j=i*i; j<=N; j+=i)
                prime[j]=1;
        }
    }
    k=0;
    for (int i=2; i<=N; i++) {
        if (!prime[i])
            primes[k++]=i;
    }
}

int main()
{
    sieve();
    int n;
    while (scanf("%d", &n) && n) {
        int ans=0;
        for (int i=0; i<k; i++) {
            if (primes[i]>n) break;
            int z=n, j=i;
            while (z>0) {
                z-=primes[j++];
            }
            if (z==0)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
