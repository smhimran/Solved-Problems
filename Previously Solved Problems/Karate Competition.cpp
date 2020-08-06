#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, ca=1, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int ans=0;
        vector<int>a(n), b(n);
        for (int i=0; i<n; i++)
            cin>>a[i];
        for (int i=0; i<n; i++)
            cin>>b[i];
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (a[j]!=-1) {
                        if (b[i]<a[j]) {
                            ans+=2;
                            a[j]=b[i]=-1;
                            break;
                        }
                }
            }
        }
        //cout<<"After Draw:"<<endl;
        for (int i=0; i<n; i++) {
            if (b[i]!=-1) {
                for (int j=0; j<n; j++) {
                    if (a[j]!=-1) {
                        if (b[i]==a[j]) {
                            ans++;
                            //cout<<ans<<endl;
                            b[i]=a[j]=-1;
                            break;
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n", ca++, ans);
    }
    return 0;
}
