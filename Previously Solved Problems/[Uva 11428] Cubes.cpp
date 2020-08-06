#include<bits/stdc++.h>
using namespace std;
int x[10001], y[10001];
bool ans[10001];

void precal()
{
    for (int i=2; i<=60; i++) {
        for (int j=i-1; j>=1; j--) {
            int k=i*i*i - j*j*j;
            if (k<=10000 && !ans[k]) {
                ans[k]=true;
                x[k]=i;
                y[k]=j;
            }
        }
    }
}

int main()
{
    precal();
    int n;
    while (cin>>n && n) {
        if (!ans[n])
            printf("No solution\n");
        else
            printf("%d %d\n", x[n], y[n]);
    }
    return 0;
}
