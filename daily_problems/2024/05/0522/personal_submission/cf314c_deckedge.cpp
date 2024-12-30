#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;
const int mod = 1e9 + 7, N = 1e6 + 7;

inline int red() {
    int x;
    cin >> x;
    return x;
}

int n, dp[N];
int64_t mx;

int query(int64_t x) {
    int64_t res = 0;
    while (x > 0) {
        res = (res + dp[x]) % mod;
        x -= x & -x;
    }
    return res;
}

void add(int64_t x, int64_t y) {
    while (x <= mx) {
        dp[x] = (dp[x] + y) % mod;
        x += x & -x;
    }
}

void solve() {
    int n = red();
    ve<int> a(n + 1);
    mx = 0;
    rep(i, 1, n + 1) {
        a[i] = red();
        mx = max(mx, (int64_t)a[i]);
    }
    memset(dp, 0, sizeof dp);
    int64_t t1, t2, res = 0, val;
    rep(i, 1, n + 1) {
        t1 = query(a[i]), t2 = query(a[i] - 1);
        val = ((t1 + 1) * a[i] - (t1 - t2 + mod) % mod) % mod;
        add(a[i], val);
        res = (res + val) % mod;
    }
    cout << res << '\n'; 
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    } 

    return 0;
}

