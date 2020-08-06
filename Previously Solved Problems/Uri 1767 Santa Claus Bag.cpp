#include<bits/stdc++.h>
using namespace std;

int weight[1002];
int amount[1002];
int dp[1002][1002];
int dir[1002][1002];
//bool mark[1002];
int us, fw;
int solve (int i, int w, int n)
{
    if (i==n)  {
        return 0;
    }
    if (dp[i][w]!=-1) return dp[i][w];
    int n1, n2;
    if (w+weight[i]<=50) {
        //mark[i]=true;
        n1=amount[i]+solve(i+1, w+weight[i], n);
    }
    else n1=0;
    n2=solve(i+1, w, n);
    if (n1>n2) {
        dir[i][w]=1;
        return dp[i][w]=n1;
    }
    else {
        dir[i][w]=2;
        return dp[i][w]=n2;
    }
}

void go(int i, int w)
{
    if (dir[i][w]==-1) return;
    if (dir[i][w]==1) {
        us++;
        fw+=weight[i];
        go(i+1, w+weight[i]);
    }
    else if(dir[i][w]==2) {
        go(i+1, w);
    }
}

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
    int t;
    cin>>t;
    while (t--) {
       int pac;
       cin>>pac;
       for (int i=0; i<pac; i++) {
            cin>>amount[i]>>weight[i];
       }
       memset(dp, -1, sizeof dp);
       memset(dir, -1, sizeof dir);
       int ans=solve(0, 0, pac);
       us=0, fw=0;
       //cout<<ans<<endl;
       go(0, 0);
       //cout<<fw<<" "<<pac-us<<endl;

       /*for (int i=0; i<pac; i++) {
            if (mark[i]) {
                //cout<<amount[i]<<" "<<weight[i]<<endl;;
                us++;
                fw+=weight[i];
            }
       }*/
       cout<<ans<<" brinquedos"<<endl;
       cout<<"Peso: "<<fw<<" kg"<<endl;
       cout<<"sobra(m) "<<pac-us<<" pacote(s)"<<endl;
       cout<<endl;
    }
    return 0;
}
