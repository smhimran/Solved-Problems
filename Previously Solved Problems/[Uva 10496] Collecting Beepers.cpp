#include<bits/stdc++.h>
using namespace std;
#define inf 1000000009

int dist (pair<int, int> a, pair<int, int> b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int main()
{
    int t;
    cin>>t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        pair<int, int> st, k;
        cin>>st.first>>st.second;
        int p;
        cin>>p;
        vector<pair<int, int> >v;
        for (int i=0; i<p; i++) {
            cin>>k.first>>k.second;
            v.push_back(k);
        }
        int dis=0;
        int mn=inf;
        do {
            dis=dist(st, v[0]);
            for (int i=1; i<p; i++) {
                dis+=dist(v[i], v[i-1]);
            }
            dis+=dist(v[p-1], st);
            mn=min(mn, dis);
        } while (next_permutation(v.begin(), v.end()));
        cout<<"The shortest path has length "<<mn<<endl;
    }
    return 0;
}
