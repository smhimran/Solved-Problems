#include<bits/stdc++.h>
using namespace std;
#define N 1000006
bool prime[N+1];

void sieve()
{
    prime[0]=prime[1]=1;
    for (int i=4; i<=N; i+=2)
        prime[i]=1;
    for (int i=3; i*i<=N; i+=2) {
        if (!prime[i]) {
            for (int j=i*i; j<=N; j+=i)
                prime[j]=1;
        }
    }
}

int main()
{
    sieve();
    int t, ca=1;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        int A[128]={0};
        for (int i=0; s[i]; i++)
            A[s[i]]++;
        int z=0;
        cout<<"Case "<<ca++<<": ";
        for (int i=0; i<128; i++) {
            if (prime[A[i]]==0) {
                printf("%c", i);
                z++;
            }
        }
        if (z==0) cout<<"empty"<<endl;
        else cout<<endl;
    }
    return 0;
}
