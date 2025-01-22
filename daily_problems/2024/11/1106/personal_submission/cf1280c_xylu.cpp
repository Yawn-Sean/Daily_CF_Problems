#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solveC() {
    int n;
    cin >> n;
    n <<= 1;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    ll mn = 0, mx = 0;
    auto dfs = [&](auto self, int u, int p) -> int {
        int sz = 1;
        for (auto [v, w] : g[u]) {
            if (v == p) continue;
            int szv = self(self, v, u);
            if (szv & 1) mn += w;
            mx += 1LL * w * min(szv, n - szv);
            sz += szv;
        }
        return sz;
    };
    dfs(dfs, 0, -1);

    cout << mn << ' ' << mx << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solveC();
    }

    return 0;
}
