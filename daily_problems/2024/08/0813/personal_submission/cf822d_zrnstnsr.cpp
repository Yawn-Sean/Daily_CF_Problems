#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int t, l, r;
    cin >> t >> l >> r;
    vector<ll> d(r + 1, -1), pr;
    for (ll i = 2; i <= r; ++i) if (d[i] < 0) {
        d[i] = i * (i - 1) / 2 % mod;
        pr.push_back(i);
        for (ll j = i * i; j <= r; j += i) d[j] = 0;
    }
    auto f = [&](auto &&self, int x) -> ll {
        if (d[x]) return d[x];
        for (auto &p: pr) {
            if (x % p == 0) {
                auto q = x / p;
                d[x] = q * d[p] % mod + self(self, q);
                break;
            }
        }
        return d[x] %= mod;
    };
    ll e = 1, ans = 0;
    for (int i = l; i <= r; ++i) {
        ans += e * f(f, i) % mod;
        ans %= mod;
        e *= t; e %= mod;
    }
    cout << ans << endl;
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
