#include<bits/stdc++.h>
using namespace std;

int codes[]={0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2};


int getCode(char c){
	return codes[((int)c)-'A'];
}

string soundex(string num)
{
    string code="0000";
    code[0]=num[0];
    int i=1, j=1, p=getCode(num[0]), c=-1;
    while (i<4 && j<num.length()) {
        c=getCode(num[j]);
        if (c!=0 && c!=p){
			code[i]=(char)(c+'0');
			i++;
		}
		p=c;
		j++;
    }
    return code;
}

void printMiddlePadding(string name){
	for (int i=name.length()+10; i<35; i++){
		cout<<" ";
	}
}

int main() {
	string name="hello";
	string front="         ";
	cout<<front<<"NAME";
	printMiddlePadding("NAME");
	cout<<"SOUNDEX CODE"<<endl;
	while (cin>>name){
		cout<<front<<name;
		printMiddlePadding(name);
		cout<<soundex(name)<<endl;
	}
	cout<<front<<front<<" "<<"END OF OUTPUT"<<endl;
	return 0;
}
