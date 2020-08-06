#include<bits/stdc++.h>
using namespace std;

string fact[400];
int cnt[10];

string multiply(string a, string b)
{
    int n1=a.size();
    int n2=b.size();
    if (n1==0||n2==0) return "0";
    vector<int>result(n1+n2, 0);
    int in1=0, in2=0;
    for (int i=n1-1; i>=0; i--) {
        int carry=0;
        int n1=a[i]-'0';
        in2=0;
        for (int j=n2-1; j>=0; j--) {
            int n2=b[j]-'0';
            int sum=n1*n2+result[in1+in2]+carry;
            carry=sum/10;
            result[in1+in2]=sum%10;
            in2++;
        }
        if (carry>0)
            result[in1+in2]+=carry;
        in1++;
    }
    int i=result.size()-1;
    while (i>=0 && result[i]==0)
        i--;
    if (i==-1) return "0";
    string ans="";
    while (i>=0)
        ans+=std::to_string(result[i--]);
    return ans;
}

void precal()
{
    fact[0]=fact[1]="1";
    for (int i=2; i<400; i++) {
        string b;
        ostringstream str1;
        str1<<i;
        b=str1.str();
        fact[i]=multiply(b, fact[i-1]);
    }
}

int main()
{
    precal();
    int n;
    while (cin>>n and n) {
        memset(cnt, 0, sizeof cnt);
        string s=fact[n];
        for (int i=0; i<s.length(); i++) {
            int x=(int)s[i]-'0';
            cnt[x]++;
        }
        printf("%d! --\n", n);
        printf("   (0)   %d   (1)   %d   (2)   %d   (3)   %d   (4)   %d\n   (5)   %d   (6)   %d   (7)   %d   (8)   %d   (9)   %d\n",cnt[0],cnt[1],cnt[2],cnt[3],cnt[4],cnt[5],cnt[6],cnt[7],cnt[8],cnt[9]);
    }
    return 0;
}
