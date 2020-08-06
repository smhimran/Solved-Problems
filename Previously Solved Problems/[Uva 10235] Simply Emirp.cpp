#include<bits/stdc++.h>
using namespace std;
#define N 1000000
bool prime[N+1];

void sieve()
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
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    sieve();
    int n;
    while (cin>>n) {
        if (prime[n]) {
            int x=0, z=n;
            while (z) {
                x=(x*10)+z%10;
                z/=10;
            }
            if (x==n)
                printf("%d is prime.\n", n);
            else if (prime[x])
                printf("%d is emirp.\n", n);
            else
                printf("%d is prime.\n", n);
        }
        else
            printf("%d is not prime.\n", n);
    }
    return 0;
}
