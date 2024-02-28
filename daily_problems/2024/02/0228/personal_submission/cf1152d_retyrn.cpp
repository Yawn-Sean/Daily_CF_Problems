// Problem: D. Neko and Aki's Prank
// Contest: Codeforces - Codeforces Round 554 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1152/D
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
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <chrono>
#include <random>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#endif

#define FAST ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define Tsolve() int T; cin >> T; while (T --) solve()
#define endl '\n'
#ifndef ONLINE_JUDGE
#include "D:/OneDrive-Personal/OneDrive/my-acm-template/my_header/debug.h"
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) {}
#endif
//-----------------------constant-----------------------
const int maxn = 1010;
const int mod = 1e9+7;
//-----------------------variable-----------------------
using namespace std;
int n;
int dp[maxn][maxn];
bool choose[maxn][maxn];
//-----------------------function-----------------------

void solve() {
    cin >> n;
    
    for (int i = 0; i <= n; i ++) {
        dp[0][i] = (i + 1) / 2;
        choose[0][i] = (i % 2);
    }
    
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            if (i == j) {
                // 只能选左
                dp[i][j] = dp[i-1][j];
                if (!choose[i][j] and !choose[i-1][j]) {
                    choose[i][j] = choose[i-1][j] = true;
                    dp[i][j] += 1;
                }
                dp[i][j] %= mod;
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                if (!choose[i][j] and !choose[i-1][j]) {
                    choose[i][j] = choose[i-1][j] = true;
                    dp[i][j] += 1;
                }
                if (!choose[i][j] and !choose[i][j-1]) {
                    choose[i][j] = choose[i][j-1] = true;
                    dp[i][j] += 1;
                }
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][n] << endl;
}
int main() {
    FAST;
    // Tsolve();
    solve();

    return 0;
}