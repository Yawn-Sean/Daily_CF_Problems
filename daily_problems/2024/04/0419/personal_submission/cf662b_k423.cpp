// https://codeforces.com/contest/662/submission/257265019

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    vector<int> red(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        char x;
        cin >> u >> v >> x, u--, v--;
        red[i] = x == 'R';
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
 
    auto Select = [&](int i, vector<int> &sel) {
        for (auto [_, id]: g[i])
            red[id] ^= 1;
        sel.emplace_back(i);
    };
    vector<int> ver(n);
    int _ver, _tar;
    function<bool(int, vector<int> &)> Dfs = [&](int i, vector<int> &sel) -> bool {
        ver[i] = _ver;
        int j, id;
        for (auto p: g[i]) {
            tie(j, id) = p;
            if (ver[j] == _ver) {
                if (red[id] != _tar) return false;
            } else {
                if (red[id] != _tar) Select(j, sel);
                if (!Dfs(j, sel)) return false;
            }
        }
        return true;
    };
    vector<vector<int>> ans(2);
    vector<int> can(2, true);
    for (int i = 0; i < n; ++i) {
        if (ver[i]) continue;
        vector<vector<int>> sel(2);
        vector<int> ok(2);
        for (_ver = 1; _ver <= 4; ++_ver) {
            vector<int> cur;
            _tar = _ver & 1;
            if (_ver & 2) Select(i, cur);
            if (Dfs(i, cur)) {
                if (!ok[_tar] || cur.size() < sel[_tar].size()) {
                    sel[_tar] = cur;
                    ok[_tar] = true;
                }
            }
            for (int j: cur)
                for (auto [_, id]: g[j])
                    red[id] ^= 1;
        }
 
        for (int k = 0; k < 2; ++k) {
            can[k] &= ok[k];
            if (can[k]) {
                for (int x: sel[k]) ans[k].emplace_back(x);
            }
        }
        if (!can[0] && !can[1]) {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> ids;
    if (can[0] && can[1]) ids = ans[0].size() < ans[1].size() ? ans[0] : ans[1];
    else ids = ans[can[1]];
    cout << ids.size() << endl;
    for (int x: ids) {
        cout << x + 1 << " \n"[x == ids.back()];
    }
}
