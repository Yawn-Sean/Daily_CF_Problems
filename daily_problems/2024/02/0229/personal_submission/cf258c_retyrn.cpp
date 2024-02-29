// Problem: C. Little Elephant and LCM
// Contest: Codeforces - Codeforces Round 157 (Div. 1)
// URL: https://codeforces.com/contest/258/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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
const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
ll gcd(ll a,ll b) { return b?gcd(b, a%b):a;}
//-----------------------variable-----------------------
int n;
template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}
    
    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<>
int MInt<0>::Mod = 1;
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
 
constexpr int P = mod;
using Z = MInt<P>;

//-----------------------function-----------------------

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    sort(all(a));
    int mx = a[n - 1];
    vector<vector<int>> p(mx + 1);
    for (int i = 1; i <= mx; i ++) {
        for (int j = i; j <= mx; j += i) {
            p[j].push_back(i);
        }
    }
    // 求前缀和
    vector<int> s(maxn); // s[i] 大于等于i的a元素个数
    for (auto x : a) {
        s[x] ++;
    }
    for (int i = 100000; i > 0; i --) {
        s[i - 1] += s[i];
    }
    
    Z res = 0;
    
    for (int i = 1; i <= mx; i ++) {
        // 枚举末尾元素 即lcm
        Z ans = 1;
        int len = sz(p[i]);
        for (int j = 1; j < len; j ++) {
            // 在[P_{j-1}, P_j)的范围内的a_i, 每个位置选择的bi都可以是p0,p1,p2...p{j-1}一共j个数
            ans *= power(Z(j), s[p[i][j - 1]] - s[p[i][j]]);
        }
        // 最后一段需要为[P_{len-1}, inf)的ai选择对应的bi P_{len-1}也就是i, 每个位置的选项都有全部的p, 刨除不选择lcm的选择
        ans *= (power(Z(len), s[i]) - power(Z(len-1), s[i]));
        res += ans;
    }
    cout << res << endl;
}
int main() {
    FAST;
    // Tsolve();
    solve();

    return 0;
}
