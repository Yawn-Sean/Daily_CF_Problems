// version1
void solve() {
    int n, m, k, mn = inf<int>;
    ll ans = 0;
    cin >> n >> m >> k;
    vi us(m), vs(m), lims(m);
    rep (i, 0, m) {
        int u, v, lim;
        cin >> u >> v >> lim;
        u--, v--;
        us[i] = u;
        vs[i] = v;
        lims[i] = lim;
        chmin(mn, abs(lim - k));
    }
    vi idx(m);
    iota(all(idx), 0);
    sort(all(idx), [&](int x, int y) {return lims[x] < lims[y];});

    UFS ufs(n, 0);
    rep (i, 0, m) {
        if (ufs.merge(us[idx[i]], vs[idx[i]]) ) {
            ans += max(0, lims[idx[i]] - k);
        }
    }
    cout << (ans ? ans : mn) << nl;
}

// version2
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi us(m), vs(m);
    priority_queue<pii, vc<pii>, greater<>> pql, pqg;
    UFS ufs(n, 0);
    rep (i, 0, m) {
        int u, v, lim;
        cin >> u >> v >> lim;
        u--, v--;
        us[i] = u;
        vs[i] = v;
        if (lim > k) pqg.emplace(lim - k, i);
        if (lim <= k) pql.emplace(k - lim, i);
    }
    int mnl = pql.empty() ? inf<int> : pql.top().first;
    while (!pql.empty()) {
        auto [v, i] = pql.top();
        pql.pop();
        ufs.merge(us[i], vs[i]);
    }
    
    int mng = pqg.empty() ? inf<int> : pqg.top().first;
    ll ans = 0;

    while (!pqg.empty()) {
        auto [v, i] = pqg.top(); pqg.pop();
        if (ufs.merge(us[i], vs[i])) {
            ans += v;
        }
    }
    cout << (ans ? ans : min(mng, mnl)) << nl;
}
