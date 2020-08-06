#include<bits/stdc++.h>
using namespace std;

#define N 10000007
bool prime[N+1];
int Z[N+1];

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
}

int sum (int n)
{
    int k, sum=0;
    while (n!=0) {
        k=n%10;
        n/=10;
        sum+=k;
    }
    return sum;
}

int main()
{
    int cnt=0;
    sieve();
    for (int i=0; i<=N; i++) {
        if (prime[i] && prime[sum(i)])
            cnt++;
        Z[i]=cnt;
    }
    int t, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        int ans=Z[b]-Z[a-1];
        printf("%d\n", ans);
    }
    return 0;
}
