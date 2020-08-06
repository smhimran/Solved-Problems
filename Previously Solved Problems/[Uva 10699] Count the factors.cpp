#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) && n) {
        int ans=0, temp=n;
        for (int i=2; i*i<=n; i++) {
            if (temp%i==0)
                ans++;
            while (temp%i==0)
                temp/=i;
        }
        if (temp!=1) ans++;
        printf("%d : %d\n", n, ans);
    }
    return 0;
}
