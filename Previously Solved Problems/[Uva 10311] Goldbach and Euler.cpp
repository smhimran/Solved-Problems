#include<bits/stdc++.h>
using namespace std;
#define N 100000001
bool prime[N+1];
vector<int> primes;
int k, x;
void sieve ()
{
    memset(prime, true, sizeof prime);
    prime[0]=prime[1]=false;
    for (int i=4; i<=N; i+=2)
        prime[i]=false;
    for (int i=3; i*i<=N; i+=2) {
        if (prime[i]==true) {
            for (int j=i*i; j<=N; j+=i)
                prime[j]=false;
        }
    }
    for (int i=2; i<=N; i++) {
        if (prime[i]==true)
            primes.push_back(i);
    }
}

bool solve(int n)
{
    if (n&1) {
        x=2;
        return prime[n-x];
    }
    int i=int(upper_bound(primes.begin(), primes.end(), n/2) - primes.begin());
    for (; i>=0; i--) {
        if (prime[n-primes[i]]) {
            if (primes[i]==n-primes[i])
                continue;
            x=min(primes[i], n-primes[i]);
            return true;
        }
    }
    return false;
}

int main()
{
    sieve();
    int n;
    while (cin>>n) {
        if (solve(n))
            printf("%d is the sum of %d and %d.\n", n, x, n-x);
        else
            printf("%d is not the sum of two primes!\n", n);
    }
    return 0;
}
