#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, f;
ll weight[1000];
vector<ll>a, b;
void solve1 (ll i, ll w, ll mw, ll q)
{
    if (i==q) {
        if (f==0 && w==0) {
            f=1;
            return;
        }
        a.push_back(w);
        return;
    }
    if (w+weight[i]<=mw)
        solve1(i+1, w+weight[i], mw, q);
    solve1(i+1, w, mw, q);
}

void solve2 (ll i, ll w, ll mw, ll q)
{
    if (i==q) {
        if (f==0 && w==0) {
            f=1;
            return;
        }
        b.push_back(w);
        return;
    }
    if (w+weight[i]<=mw)
        solve2(i+1, w+weight[i], mw, q);
    solve2(i+1, w, mw, q);
}

int main()
{
    ll t, ca=1;
    cin>>t;
    while (t--) {
        a.clear();
        b.clear();
        ll w;
        cin>>n>>w;
        for (ll i=0; i<n; i++)
            cin>>weight[i];
        ll q=(n)/2;
        f=0;
        solve1(0, 0, w, q);
        f=0;
        solve2(q, 0, w, n);
        sort(b.begin(), b.end());
        ll ct=1;
        for (int i=0; i<a.size(); i++) {
            if (a[i]<=w)
                ct++;
        }
        for (int i=0; i<b.size(); i++) {
            if (b[i]<=w)
                ct++;
        }
        ll d, l;
        for (int i=0; i<a.size(); i++) {
            d=w-a[i];
            l=upper_bound(b.begin(), b.end(), d)-b.begin();
            ct+=l;
        }
        cout<<"Case "<<ca++<<": "<<ct<<endl;
    }
    return 0;
}

