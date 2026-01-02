//20260102_cf104468m_Travor007.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vi;
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

ll fac[MX], ifac[MX];
void init() {
    fac[0] = 1;
    for (int i = 1; i < MX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    ifac[MX - 1] = inv_mod(fac[MX - 1], MOD);
    for (int i = MX - 2; i >= 0; i--) {
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi s(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    ll ans = fac[n];
    for (int i = 1; i <= k; i++) {
        ans = ans * ifac[s[i] - s[i - 1]] % MOD;
    }
    ans = ans * ifac[n - s[k]] % MOD;
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
