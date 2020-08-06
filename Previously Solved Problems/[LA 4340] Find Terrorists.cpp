#include<bits/stdc++.h>
using namespace std;
#define N 10000
bool isprime[N+1];
int facts[N+1];
void sieve()
{
    memset(isprime, true, sizeof isprime);
    isprime[0]=isprime[1]=false;
    for (int i=4; i<=N; i+=2)
        isprime[i]=false;
    for (int i=3; i*i<=N; i+=2) {
        if (isprime[i]) {
            for (int j=i*i; j<=N; j+=i)
                isprime[j]=false;
        }
    }
}

void factor()
{
    for (int i=2; i<=100; i++) {
        int n=i*i;
        int z=0;
        for (int i=1; i*i<=n; i++) {
            if (n%i==0) {
                if (n/i==i)
                    z++;
                else
                    z+=2;
            }
        }
        facts[i*i]=z;
        //cout<<i*i<<": "<<facts[i*i]<<endl;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    sieve();
    factor();
    int t;
    scanf("%d", &t);
    while (t--) {
        int l, h;
        bool flag=false;
        scanf("%d %d", &l, &h);
        for (int i=l; i<=h; i++) {
            if (isprime[i]) {
                if (!flag) {
                    printf("%d", i);
                }
                else
                    printf(" %d", i);
                flag=true;
            }
            else if (isprime[facts[i]]) {
                if (!flag) {
                    printf("%d", i);
                }
                else
                    printf(" %d", i);
                flag=true;
            }
        }
        if (!flag)
            printf("-1");
        printf("\n");
    }
    return 0;
}
