#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int, int, int>> edges;
    vector<int> fa(n+1);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    int cnt = n;
    auto find = [&](auto &&self, int u) -> int {
        return fa[u] == u ? u : fa[u] = self(self, fa[u]);
    };
    auto merge = [&](int u, int v) {
        u = find(find, u); v = find(find, v);
        if (u != v) { fa[u] = v; --cnt; }
    };
    int small = -inf, big = inf;
    long long ans;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w <= k) {
            small = max(w, small);
            merge(u, v);
        } else {
            edges.push_back({w, u, v});
            big = min(w, big);
        }
    }
    if (cnt == 1) ans = min(k - small, big - k);
    else {
        ans = 0;
        sort(edges.begin(), edges.end());
        auto it = edges.begin();
        while (cnt > 1) {
            auto [w, u, v] = *it++;
            int t = cnt;
            merge(u, v);
            if (t != cnt) ans += w - k;
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
