// Problem: A. NP-Hard Problem
// Contest: Codeforces - Codeforces Round 360 (Div. 1)
// URL: https://codeforces.com/problemset/problem/687/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <cstring>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#define FAST ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15)
#define endl '\n'
#define em(x) (x.empty())
#define sz(x) ((int)(x).size())
using pii = std::pair<int,int>;
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }

//-----------------------variable-----------------------
int n, m;

//-----------------------function-----------------------

void solve() {
    cin >> n >> m;
    vector<pii> E;
    vector<vector<int>> g(n);
    while (m --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
        g[y].push_back(x);
        E.push_back({x, y});
    }
    
    vector<int> f(n, 0);
    
    for (int i = 0; i < n; i ++) {
        if (f[i]) continue;
        queue<int> q;
        f[i] = 1;
        q.push(i);
        while (sz(q)) {
            auto t = q.front();
            q.pop();
            for (auto x : g[t]) {
                if (f[x] == 0) {
                    f[x] = 3 - f[t];
                    q.push(x);
                }
            }
        }
    }
    
    for (auto [x, y] : E) {
        if (f[x] == f[y]) {
            cout << -1 << endl;
            return;
        }
    }
    
    for (int u = 1; u <= 2; u ++) {
        vector<int> res;
        for (int i = 0; i < n; i ++) {
            if (f[i] == u) res.push_back(i + 1);
        }
        cout << sz(res) << endl;
        cout << res << endl;
    }
}
int main() {
    FAST;
    solve();

    return 0;
}
