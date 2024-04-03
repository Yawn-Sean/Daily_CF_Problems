// https://codeforces.com/contest/739/submission/254648588

/* 我永远喜欢爱莉希雅♪ */
using i64 = int64_t;
using pii = pair<int, int>;
 
void elysia() {
    int n;
    cin >> n;
    vector<int> val(n);
    vector<i64> dis(n);
    vector<vector<pii>> g(n);
    for (int &x: val) cin >> x;
    for (int i = 1; i < n; ++i) {
        int p, w;
        cin >> p >> w, p--;
        g[p].emplace_back(i, w);
    }
 
    function<void(int)> dfs = [&](int u) {
        for (auto [v, w]: g[u]) {
            dis[v] = dis[u] + w;
            dfs(v);
        }
    };
    dfs(0);
 
    vector<i64> cp = dis;
    for (int i = 0; i < n; ++i) cp[i] -= val[i];
    ranges::sort(cp);
    cp.erase(ranges::unique(cp).begin(), cp.end());
    fenwick<int> fcc(cp.size());
    vector<int> ans(n);
    function<void(int)> calc = [&](int u) {
        int i = ranges::upper_bound(cp, dis[u] - val[u]) - cp.begin() - 1;
        int j = ranges::upper_bound(cp, dis[u]) - cp.begin() - 1;
        fcc.modify(i, 1);
        ans[u] -= fcc.get(j);
        for (auto [v, w]: g[u]) calc(v);
        ans[u] += fcc.get(j);
    };
    calc(0);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}
