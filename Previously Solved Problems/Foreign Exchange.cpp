#include<bits/stdc++.h>
using namespace std;

int arr[1000006];

int main()
{
    int t;
    while (scanf("%d", &t) && t) {
        bool flag=true;
        memset(arr, 0, sizeof(arr));
        int a, b;
        while (t--) {
            scanf("%d %d", &a, &b);
            arr[a]--;
            arr[b]++;
        }
        for (int i=0; i<1000006; i++) {
            if (arr[i]!=0) {
                flag=false;
                break;
            }
        }
        printf("%s\n", flag? "YES":"NO");
    }
    return 0;
}
