void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi us(m), vs(m);
    priority_queue<pii, vc<pii>, greater<>> pql, pqg;
    set<int> s;
    rep (i, 0, n) s.insert(i);
    rep (i, 0, m) {
        int u, v, lim;
        cin >> u >> v >> lim;
        u--, v--;
        us[i] = u;
        vs[i] = v;
        if (lim > k) pqg.emplace(lim - k, i);
        if (lim <= k) pql.emplace(k - lim, i);
    }
    vector<int> vis(n);
    int ans = pql.empty() ? inf<int> : pql.top().first;
    while (!pql.empty()) {
        auto [v, i] = pql.top();
        pql.pop();
        if (vis[us[i]] and vis[vs[i]]) continue;
        vis[us[i]] = vis[vs[i]] = 1;
        s.erase(us[i]);
        s.erase(vs[i]);
    }
    if (!pqg.empty()) chmin(ans, pqg.top().first);

    while (s.size()) {
        auto [v, i] = pqg.top(); pqg.pop();
        if (vis[us[i]] and vis[vs[i]]) continue;
        ans += v;
        vis[us[i]] = vis[vs[i]] = 1;
        s.erase(us[i]);
        s.erase(vs[i]);
    }
    cout << ans << nl;
}
