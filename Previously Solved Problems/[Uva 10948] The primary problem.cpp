#include<bits/stdc++.h>
using namespace std;
#define N 1000006
bool prime[N+1];
vector<int>primes;
void sieve ()
{
    memset(prime, true, sizeof prime);
    prime[0]=prime[1]=false;
    for (int i=4; i<=N; i+=2)
        prime[i]=false;
    for (int i=3; i*i<=N; i+=2) {
        if (prime[i]) {
            for (int j=i*i; j<=N; j+=i)
                prime[j]=false;
        }
    }
    for (int i=2; i<=N; i++) {
        if (prime[i])
            primes.push_back(i);
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    sieve();
    int n;
    while (cin>>n && n) {
        int x=upper_bound(primes.begin(), primes.end(), n)-primes.begin();
        bool flag=false;
        int k, z;
        for (int i=x-1; i>=0; i--) {
            k=n-primes[i];
            if (prime[k]) {
                z=primes[i];
                flag=true;
                break;
            }
        }
        printf("%d:\n", n);
        if (flag)
            printf("%d+%d\n", k, z);
        else
            printf("NO WAY!\n");
    }
    return 0;
}
