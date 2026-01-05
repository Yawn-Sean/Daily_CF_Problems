//20260105_cf104287h_Travor007.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vi;
const char nl = '\n';
const ll MOD = 1e9 + 7;
const int MX = 2e5 + 5;

ll pow_mod(ll a, ll n, ll mod) {
    a %= mod;
    ll res = 1;
    while (n) {
        if (n % 2)
            res = res * a % mod;
        a = a * a % mod;
        n /= 2;
    }
    res %= mod;
    if (res < 0)
        res += mod;
    return res;
}

void solve() {
    ll d;
    cin >> d;

    ll term1 = ((d - 3 + MOD) % MOD) * pow_mod(2, 2 * d + 1, MOD) % MOD;

    ll term2 = ((d + 3) % MOD) * pow_mod(2, d + 1, MOD) % MOD;

    ll ans = (term1 + term2) % MOD;
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
