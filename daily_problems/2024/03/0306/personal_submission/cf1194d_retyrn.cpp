// Problem: D. 1-2-K Game
// Contest: Codeforces - Educational Codeforces Round 68 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1194/D
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
int n, k;

//-----------------------function-----------------------

void solve() {
    cin >> n >> k;
    if (n < k or k % 3 != 0) {
        if (n % 3 == 0) {
            // Alice必输
            cout << "Bob" << endl;
            return;
        }
        cout << "Alice" << endl;
        return;
    }
    // k是3的倍数
    // k必胜 k-1必胜 1必胜 -> k+1必败
    // k+2 k+3 2k+1 必胜 4必胜 k+4必败
    // k+5 k+6 必胜 7必胜 k+7必败

    int u = n % (k + 1);
    if (u == k or u % 3) {
        // 必败
        cout << "Alice" << endl;
        return;
    }
    cout << "Bob" << endl;
}
int main() {
    FAST;
    Tsolve();
    // solve();

    return 0;
}
