/**
 * Problem: E. Let's Go Rolling!
 * Contest: School Personal Contest #1 (Winter Computer School 2010/11)
 * OnlineJudge: Codeforces
 * @Author: Chizer
 * DateTime: 2025-05-26 15:59
 * 适度编程益脑，沉迷编程伤身，合理安排时间，享受快乐生活。
 */
#include "bits/stdc++.h"
#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define dep(i, j, k) for(int i = (j); i >= (k); --i)
using i64 = int64_t;
using f64 = double_t;
#define pb push_back
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define ull unsigned long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define maxn 100005
using namespace std;

int T;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    rep(i, 1, n) {
        int x, c;
        cin >> x >> c;
        v.pb({ x, c });
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vector<ll> dp(n + 1, 1e18);
    vector<ll> pre(n + 1, 0);
    for(int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + v[i].first;
    }
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            dp[i + 1] = min(dp[i + 1], dp[j] + v[i].second + pre[i] - pre[j] - 1ll * v[i].first * (i - j));
        }
    }
    cout << dp[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    //    cin >> T;
    while(T--) solve();
}
