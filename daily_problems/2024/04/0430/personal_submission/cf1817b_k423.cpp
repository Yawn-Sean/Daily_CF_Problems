// https://codeforces.com/contest/1817/submission/258933804

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
 
    vector<int> act(n), vis(n), fa(n);
    for (int i = 0; i < n; ++i) {
        if (g[i].size() < 4) continue;
        act.assign(n, 0);
        for (int j: g[i]) act[j] = 1;
        queue<int> Q;
        for (int j: g[i]) {
            vis.assign(n, 0), fa.assign(n, -1);
            Q.emplace(j);
            act[j] = 0;
            vis[i] = vis[j] = 1;
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                for (int v: g[u]) {
                    if (act[v]) {
                        fa[v] = u;
                        YES();
                        set<int> S(itr(g[i]));
                        S.extract(j), S.extract(v);
                        while (S.size() > 2) S.erase(S.begin());
                        S.insert(j), S.insert(v);
                        vector<pair<int, int>> ans;
                        for (int x: S) ans.emplace_back(i, x);
                        while (v != j) {
                            ans.emplace_back(v, fa[v]);
                            v = fa[v];
                        }
                        cout << ans.size() << endl;
                        for (auto &[x, y]: ans) {
                            cout << x + 1 << ' ' << y + 1 << endl;
                        }
                        return;
                    }
                    if (vis[v]) continue;
                    vis[v] = 1, fa[v] = u;
                    Q.emplace(v);
                }
            }
            act[j] = 1;
        }
    }
    NO();
}
