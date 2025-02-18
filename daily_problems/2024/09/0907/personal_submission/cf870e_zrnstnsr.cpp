#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

ll qpow(int e, int N) {
    if (!e) return 1 % mod;
    ll res = qpow(e / 2, N);
    res *= res;
    res %= mod;
    if (e % 2) res *= N, res %= mod;
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> fa(2*n);
    ranges::iota(fa, 0);
    auto find = [&](this auto &&self, int u) -> int { return fa[u] == u ? fa[u] : fa[u] = self(fa[u]); };
    auto merge = [&](int u, int v) -> void { u = find(u); v = find(v); if (u != v) fa[u] = v; };

    int tot = 0;
    map<int, int> xid, yid;
    vector<pair<int, int>> pt(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (!xid.count(x)) xid[x] = tot++;
        if (!yid.count(y)) yid[y] = tot++;
        merge(xid[x], yid[y]);
        pt[i] = {xid[x], yid[y]};
    }
    map<int, int> sz, ed;
    for (int i = 0; i < tot; ++i) ++sz[find(i)];
    for (auto [u, _]: pt) ++ed[find(u)];
    ll ans = 1;
    for (auto [no, m]: sz) {
        if (ed[no] >= m) ans *= qpow(m, 2);
        else ans *= qpow(m, 2) - 1;
        ans %= mod;
    }
    println("{}", ans);
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
