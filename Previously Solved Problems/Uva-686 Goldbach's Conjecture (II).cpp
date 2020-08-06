#include<bits/stdc++.h>
using namespace std;
#define N 1000006

bool isprime[N+1];
vector<int> primes;
bool mark[N+1];
set<pair<int, int> >p;

void sieve ()
{
    for (int i=4; i<=N; i+=2) {
        isprime[i]=true;
    }
    for (int i=3; i*i<=N; i+=2) {
        if (!(isprime[i])) {
            for (int j=i*2; j<=N; j+=i)
                isprime[j]=true;
        }
    }
    for (int i=2; i<=N; i++) {
        if (!isprime[i])
            primes.push_back(i);
    }
}

int main()
{
    sieve();
    int n;
    while (cin>>n && n!=0) {
        int up=upper_bound(primes.begin(), primes.end(), n)-primes.begin();
        int k=primes[up-1];
        int x=0;
        int cnt=0;
        for (int i=up-1; i>=0; i--) {
            x=n-primes[i];
            if (x> primes[i]) break;
            if (binary_search(primes.begin(), primes.end(), x)) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
