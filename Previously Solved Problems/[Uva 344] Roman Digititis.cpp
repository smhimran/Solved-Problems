#include<bits/stdc++.h>
using namespace std;
int i[105], v[105], x[105], l[105], c[105];
string toRoman(int num)
{

     string m[] = {"", "m", "mm", "mmm"};
     string c[] = {"", "c", "cc", "ccc", "cd", "d",
                        "dc", "dcc", "dccc", "cm"};
     string x[] = {"", "x", "xx", "xxx", "xl", "l",
                        "lx", "lxx", "lxxx", "xc"};
     string i[] = {"", "i", "ii", "iii", "iv", "v",
                        "vi", "vii", "viii", "ix"};
     //string thousands = m[num/1000];
     string hundereds = c[(num%1000)/100];
     string tens =  x[(num%100)/10];
     string ones = i[num%10];
     string ans = hundereds + tens + ones;
     return ans;
}

void precal()
{
    string s;
    for (int p=1; p<=100; p++) {
        s=toRoman(p);
        for (int j=0; s[j]; j++) {
            if (s[j]=='i') i[p]++;
            else if (s[j]=='v') v[p]++;
            else if (s[j]=='x') x[p]++;
            else if (s[j]=='l') l[p]++;
            else if (s[j]=='c') c[p]++;
        }
        i[p]+=i[p-1];
        v[p]+=v[p-1];
        x[p]+=x[p-1];
        l[p]+=l[p-1];
        c[p]+=c[p-1];
    }
}

int main()
{
    precal();
    int n;
    while (cin>>n and n) {
        printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, i[n], v[n], x[n], l[n], c[n]);
    }
    return 0;
}
