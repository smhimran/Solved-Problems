#include <bits/stdc++.h>
using namespace std;

string longDivision(string number, int divisor)
{
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
       temp = temp * 10 + (number[++idx] - '0');
    while (number.size() > idx)
    {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    if (ans.length() == 0)
        return "0";
    return ans;
}

string add(string a, string b)
{
    if (a.length()>b.length())
        swap(a,b);
    string ans="";
    int n1=a.length(), n2=b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry=0, sum=0;
    for (int i=0; i<n1; i++) {
        sum=(a[i]-'0')+(b[i]-'0')+carry;
        ans.push_back(sum%10+'0');
        carry=sum/10;
    }
    for (int i=n1; i<n2; i++) {
        sum=((b[i]-'0')+carry);
        ans.push_back(sum%10+'0');
        carry=sum/10;
    }
    if (carry)
        ans.push_back(carry+'0');
    reverse(ans.begin(), ans.end());
    return ans;
}


int main()
{
	int n, f, bill=0;
	while (cin>>n>>f and n||f) {
	    if (bill) cout<<endl;
	    bill++;
	    string s, sum="", div="";
	    while (n--) {
	        cin>>s;
	        sum=add(sum, s);
	    }
	    div=longDivision(sum, f);
	    cout<<"Bill #"<<bill<<" costs "<<sum<<":"<<" each friend should pay "<<div<<endl;
	}
	cout<<endl;
	return 0;
}
