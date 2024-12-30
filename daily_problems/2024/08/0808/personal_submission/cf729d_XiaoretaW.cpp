/*
    首先 ans <= 3，并且如果 ans != 0 的话这个图退化成了一个森林
    1. ans = 0: 存在奇环，方案数目即为 1
    2. ans = 1: 有一条长度为 2 的链，方案数 = 一条链的起点，终点距离起点为奇数的点的个数，这里可以通过二分图解决，因为对于一个颜色的起点来说，距离起点为奇数的点一定为另一个颜色，所以可以通过组合数求解
    3. ans = 2: 若干个长度小于等于 1 的链，方案数 = (n - 2) * cnt2
    4. ans = 3: 若干个孤立点，方案数 = C(n, 3) = n * (n - 1) * (n - 2) / 6
*/
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
    DSU dsu(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        dsu.merge(u, v);
    }

    // 4
    if (m == 0) {
        cout << 3 << ' ' <<  1ll * n * (n - 1) * (n - 2) / 6 << '\n';
        return 0;
    }

    // 3
    bool ok = true;
    int cnt2 = 0;
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (dsu.size(i) == 2 && !vis[dsu.leader(i)]) {
            ++cnt2;
            vis[dsu.leader(i)] = 1;
        } else {
            if (dsu.size(i) > 2) {
                ok = false;
                break;
            }
        }
    }

    if (ok) {
        cout << 2 << ' ' << 1ll * cnt2 * (n - 2) << '\n';
        return 0;
    }

    // 1
    bool odd = false;
    vector<int> color(n + 1, -1);
    auto dfs = [&](auto dfs, int u, int c) -> void {
        color[u] = c;
        for (int v : g[u]) {
            if (color[v] == -1) dfs(dfs, v, c ^ 1);
            else if (color[u] == color[v]) odd = true;
        }
    };
    for (int i = 1; i <= n; i++) if (color[i] == -1) {
        dfs(dfs, i, 0);
    }
    if (odd) {
        cout << 0 << ' ' << 1 << '\n';
        return 0;
    }

    // 2
    ll ans = 0;
    vector<vector<int>> bel(n + 1);
    for (int i = 1; i <= n; i++) bel[dsu.leader(i)].emplace_back(i);
    for (int i = 1; i <= n; i++) {
        array<int, 2> cnt; cnt.fill(0);
        for (int v : bel[i]) {
            ++cnt[color[v]];
        }
        ans += 1ll * cnt[0] * (cnt[0] - 1) / 2 + 1ll * cnt[1] * (cnt[1] - 1) / 2;
    }

    cout << 1 << ' ' << ans << '\n';

    return 0;
}
