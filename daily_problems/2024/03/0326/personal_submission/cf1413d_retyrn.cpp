// Problem: D. Shurikens
// Contest: Codeforces - Technocup 2021 - Elimination Round 1
// URL: https://codeforces.com/problemset/problem/1413/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <cassert>
#include <cctype>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <chrono>
#include <random>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#endif
 
#define FAST ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15)
#define Tsolve() int T; cin >> T; while (T --) solve()
#define endl '\n'
#define em(x) (x.empty())
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mem(a,b) memset(a,b,sizeof(a))
#define Fill(x,a) memset(x,a,sizeof(x))
#define cpy(a,b) memcpy(a,b,sizeof(a))
#define pbk push_back
#define mpr make_pair
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,n) for(int i=a;i<=n;++i)
#define fi first
#define se second
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
//-----------------------precompiler--------------------
using ll = long long;
using i64 = long long;
using pii = std::pair<int,int>;
using VI = std::vector<int>;
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
//-----------------------debug-----------------------
#ifndef ONLINE_JUDGE
#include "D:/OneDrive-Personal/OneDrive/my-acm-template/my_header/debug.h"
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) {}
#endif
//-----------------------constant-----------------------
const int maxn = 2e5+10;
const int inf = 0x3f3f3f3f;
const ll inf2 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9+7;
const int mod2 = 998244353;
ll gcd(ll a,ll b) { return b?gcd(b, a%b):a;}
//-----------------------variable-----------------------
int n;

//-----------------------function-----------------------
 
void solve() {
    cin >> n;
    // 优先放贵的匕首
    vector<vector<int>> v;
    for (int i = 0; i < (n << 1); i ++) {
        string op;
        cin >> op;
        int t = (op[0] == '+' ? 1 : -1);
        if (em(v) or v.back()[0] != t) {
            if (t == -1) v.push_back({t});
            else v.push_back({t, 0});
        }
        if (t == -1) {
            int x;
            cin >> x;
            v.back().push_back(x);
        }
        else {
            v.back()[1] += 1;
        }
    }
    
    for (auto& vec : v) {
        if (vec[0] == 1) continue;
        // 删除的每一段必须单调递增
        for (int i = 2; i < sz(vec); i ++) {
            if (vec[i] < vec[i-1]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
 
    vector<bool> st(n + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    int idx = n;
    vector<int> res;
    for (auto& vec : v) {
        if (vec[0] == 1) {
            int cnt = vec[1];
            while (cnt > 0) {
                while (idx > 0 and st[idx]) idx --;
                st[idx] = true;
                res.push_back(idx);
                q.push({idx, sz(res) - 1});
                idx --;
                cnt --;
            }
            continue;
        }
        for (int i = 1; i < sz(vec); i ++) {
            if (st[vec[i]]) {
                if (em(q) or q.top().fi != vec[i]) {
                    cout << "NO" << endl;
                    return;
                }
                q.pop();
                continue;
            }
            else if (sz(q)) {
                // 开始反悔
                auto [val, pos] = q.top();
                q.pop();
                res[pos] = vec[i];
                st[val] = false;
                idx = val;
            }
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    // check
    int p = 0;
    priority_queue<int, VI, greater<int>> q1;
    for (auto& vec : v) {
        if (vec[0] == 1) {
            int cnt = vec[1];
            while (cnt > 0) {
                q1.push(res[p ++]);
                cnt --;
            }
        }
        else {
            for (int i = 1; i < sz(vec); i ++) {
                if (em(q1) or q1.top() != vec[i]) {
                    cout << "NO" << endl;
                    return;
                }
                q1.pop();
            }
        }
    }
    cout << "YES" << endl << res << endl;
}
int main() {
    FAST;
    // Tsolve();
    solve();
 
    return 0;
}