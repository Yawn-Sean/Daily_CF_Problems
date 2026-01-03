//cf104786c_Travor007.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<ll> vl;
const char nl = '\n';
const ll MOD = 1e9 + 7;
const int MX = 2e5 + 5;

// clang-format off
// 计算a^n(mod p)和模逆元a^(-1)(mod p)
ll pow_mod(ll a, ll n, ll mod) {
    a %= mod;
    ll res = 1;
    while (n) {
        if (n % 2) res = res * a % mod;
        a = a * a % mod;
        n /= 2;
    }
    res %= mod;
    if (res < 0) res += mod;
    return res;
}

ll inv_mod(ll a, ll mod) {
    return pow_mod(a, mod - 2, mod);  // 费马小定理
}
// clang-format on

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<vl> dp(n + 2, vl(n + 2, 0));
    ll inv2 = inv_mod(2, MOD);

    for (int o = n; o >= x; o--) {
        for (int j = x; j <= n; j++) {
            if (j <= o) {
                dp[o][j] = 0;
            } else if (j == n) {
                dp[o][j] = (1 + dp[o + 1][j - 1]) % MOD;
            } else {
                dp[o][j] =
                    (1 + inv2 * dp[o + 1][j - 1] % MOD + inv2 * dp[o + 1][j + 1] % MOD) % MOD;
            }
        }
    }
    cout << dp[x][y] << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
