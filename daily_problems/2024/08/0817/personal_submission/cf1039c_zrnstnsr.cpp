#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

ll pow2[500010];

#define Fa(x) find(find, x)

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> fa(n+1);
    int tot = n;
    iota(fa.begin(), fa.end(), 0);
    auto find = [&](auto &&self, int u) -> int { return fa[u] == u ? fa[u] : fa[u] = self(self, fa[u]); };
    auto merge = [&](int u, int v) { u = Fa(u); v = Fa(v); if (u != v) --tot, fa[u] = v; };

    vector<ll> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    map<ll, vector<pair<int, int>>> e;
    while (m--) {
        int u, v;
        cin >> u >> v;
        e[a[u]^a[v]].push_back({u, v});
    }
    ll ans = pow2[n] * (pow2[k] + mod - e.size()) % mod;
    set<int> st;
    for (auto &[x, vec]: e) {
        for (auto u: st) fa[u] = u;
        tot = n; st.clear();
        for (auto [u, v]: vec) merge(u, v), st.insert(u), st.insert(v);
        ans += pow2[tot];
        ans %= mod;
    }
    cout << ans << '\n';
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    pow2[0] = 1;
    for (int i = 1; i <= 500000; ++i) pow2[i] = pow2[i-1] << 1, pow2[i] %= mod;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
