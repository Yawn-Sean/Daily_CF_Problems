//20260120_cf105813j_Travor007.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;
const int MX = 3e5 + 12;
const char nl = '\n';

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

void solve() {
    int n, k;
    cin >> n >> k;

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
    }

    ll ans = (sum % MOD) * inv_mod(n, MOD) % MOD;
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
