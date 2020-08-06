#include<bits/stdc++.h>
using namespace std;

int UG[1509];

int Ugly(int n)
{
    UG[0]=1;
    int i2=0, i3=0, i5=0;
    int next_ugly, next2=UG[i2]*2, next3=UG[i3]*3, next5=UG[i5]*5;
    for (int i=1; i<n; i++) {
        next_ugly=min(next2, min(next3, next5));
        UG[i]=next_ugly;
        if (next_ugly==next2) {
            i2++;
            next2=UG[i2]*2;
        }
        if (next_ugly==next3) {
            i3++;
            next3=UG[i3]*3;
        }
        if (next_ugly==next5) {
            i5++;
            next5=UG[i5]*5;
        }
    }
    return next_ugly;
}

int main()
{
    int n=1500;
    cout<<"The 1500'th ugly number is "<<Ugly(n)<<"."<<endl;
    return 0;
}
