// Problem: B. Petr and Permutations
// Contest: Codeforces - Codeforces Round 485 (Div. 1)
// URL: https://codeforces.com/problemset/problem/986/B
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
int n;
template<typename T>
struct BIT{
#ifndef lowbit
#define lowbit(x) (x & (-x))
#endif
    int n;
    std::vector<T> tr;

    BIT<T> () {}
    BIT<T> (int _n): n(_n), tr(n + 10, 0) {}
    BIT<T> (int _n, T *a): n(_n), tr(n + 10, 0){
        /* 从 1 开始 */
        for (int i = 1; i <= n; ++ i){
            tr[i] += a[i];
            int j = i + lowbit(i);
            if (j <= n) tr[j] += tr[i];
        }
    }

    void add(int x, T c){
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }

    /* 1-index */
    T sum(int x){
        T res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }
    /* 1-index [l, r] */
    T sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
};

//-----------------------function-----------------------

void solve() {
    // 每次交换 逆序对的变化都是奇数
    cin >> n;
    vector<int> a(n);
    cin >> a;
    BIT<int> bit(n);
    ll cnt = 0;
    for (int i = 0; i < n; i ++) {
        cnt += bit.sum(a[i] + 1, n);
        bit.add(a[i], 1);
    }
    // 逆序对数和n同奇偶
    if ((cnt & 1) == (n & 1)) {
        cout << "Petr" << endl;
    }
    else {
        cout << "Um_nik" << endl;
    }
}
int main() {
    FAST;
    // Tsolve();
    solve();

    return 0;
}