// Problem: E. Permutation by Sum
// Contest: Codeforces - Codeforces Round 713 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1512/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
#define EX (exit(0))
#define em(x) (x.empty())
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mem(a,b) memset(a,b,sizeof(a))
#define Fill(x,a) memset(x,a,sizeof(x))
#define cpy(a,b) memcpy(a,b,sizeof(a))
#define pbk push_back
#define ebk emplace_back
#define mpr make_pair
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,n,a) for(int i=n;i>=a;--i)
#define fi first
#define se second
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
//-----------------------precompiler--------------------
using ll = long long;
using LL = long long;
using ull = unsigned long long;
using ULL = unsigned long long;
using i64 = long long;
using u64 = unsigned long long;
using db = double;
using pii = std::pair<int,int>;
using PII = std::pair<int,int>;
using pll = std::pair<long long, long long>;
using PLL = std::pair<long long, long long>;
using VI = std::vector<int>;
using VVI = std::vector<std::vector<int>>;
using VLL = std::vector<ll>;
using VB = std::vector<bool>;
using VPII = std::vector<PII>;
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
int n, l, r, s;

//-----------------------function-----------------------

void solve() {
    cin >> n >> l >> r >> s;
    vector<int> a(n + 1, 0);
    int len = r - l + 1;
    int lower = (1 + len) * len / 2;
    int upper = (n + n - len + 1) * len / 2;
    if (s > upper or s < lower) {
        cout << -1 << endl;
        return;
    }
    int need = s - lower;
    for (int i = l; i <= r; i ++) {
        a[i] = i - l + 1 + (need / len);
    }
    need %= len;
    for (int i = r; i >= l and need; i --) {
        a[i] += 1;
        need -= 1;
    }
    VB st(n + 1, false);
    for (int i = l; i <= r; i ++) {
        st[a[i]] = true;
    }
    
    for (int i = 1, j = 1; i <= n; i ++) {
        if (a[i]) continue;
        while (j <= n and st[j]) j ++;
        a[i] = j;
        st[j] = true;
    }
    for (int i = 1; i <= n; i ++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
int main() {
    FAST;
    Tsolve();
    // solve();

    return 0;
}
