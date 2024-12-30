#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> fact(n+1), inv_fact(n+1);
    // from tourist
    auto inverse = [&](ll a) -> ll {
        ll u = 0, v = 1, m = mod;
        while (a) {
            ll t = m / a;
            m -= t * a; swap(a, m);
            u -= t * v; swap(u, v);
        }
        return (u % mod + mod) % mod;
    };
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1] * i % mod, inv_fact[i] = inverse(fact[i]);

    vector<pair<int,int>> tr(n);
    vector<int> x(2*n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        tr[i] = { l, r };
        x[i*2] = l; x[i*2+1] = r + 1;
    }
    sort(x.begin(), x.end());
    auto it = unique(x.begin(), x.end());
    x.erase(it, x.end());
    int m = x.size();
    for (int i = 0; i < m; ++i) mp[x[i]] = i;
    vector<int> d(m), len(m - 1);
    for (int i = 0; i < m - 1; ++i) len[i] = x[i+1] - x[i];
    for (auto [l, r]: tr) ++d[mp[l]], --d[mp[r+1]];
    for (int i = 1; i < m; ++i) d[i] += d[i-1];
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        if (d[i] >= k) ans += fact[d[i]] * inv_fact[k] % mod * inv_fact[d[i]-k] % mod * len[i] % mod, ans %= mod;
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
