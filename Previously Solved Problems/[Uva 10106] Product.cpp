#include<bits/stdc++.h>
using namespace std;

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
        ans.push_back(result[i--]+'0');
    return ans;
}

int main()
{
    string a, b;
    while (cin>>a>>b) {
        cout<<multiply(a, b)<<endl;
    }
    return 0;
}
