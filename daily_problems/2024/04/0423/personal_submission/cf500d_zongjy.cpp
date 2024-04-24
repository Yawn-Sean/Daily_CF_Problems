#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(nullptr);

void solve() {
    int n;
    cin >> n;
    vector<vector<pii>> g(n + 1);
    map<int, double> edge;
    int u, v, w;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
        edge[i] = (double)w;
    }
    vector<int> sz(n + 1);
    function<int(int, int)> dfs1 = [&](int uu, int fa) -> int {
        sz[uu] = 1;
        for (auto [vv, id] : g[uu]) {
            if (vv == fa) continue;
            sz[uu] += dfs1(vv, uu);
        }
        return sz[uu];
    };
    dfs1(1, 0);

    i64 b = (i64) n * (n - 1) * (n - 2) / 6;
    vector<double> val(n);
    function<void(int, int)> dfs2 = [&](int high, int fa) -> void {
        for (auto [low, id] : g[high]) {
            if (low == fa) continue;
            i64 l = n - sz[low], r = sz[low];
            val[id] = (double)(l * (l - 1) * r) / b + (double) l * r * (r - 1) / b;
            dfs2(low, high);
        }
    };
    dfs2(1, 0);

    double init = 0;
    for (int i = 1; i <= n - 1; i++) {
        init += val[i] * edge[i];
    }

    int q, eid;
    double env;
    cin >> q;
    while (q--) {
        cin >> eid >> env;
        init -= (edge[eid] - env) * val[eid];
        edge[eid] = env;
        printf("%.10f\n", init);
    }
}

int main() {
    IOS;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}