// https://codeforces.com/contest/645/submission/257684524

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    vector<pii> adjs(m);
    vector<vector<pii>> g(n);
    for (int i = 0; i < m; ++i) {
        auto &[u, v] = adjs[i];
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v, i);
    }

    auto check = [&](int k) -> bool {
        vector<int> deg(n);
        queue<int> Q;
        for (int i = 0; i < k; ++i) {
            deg[adjs[i].second]++;
        }
        for (int i = 0; i < n; ++i) if (!deg[i]) Q.emplace(i);
        while (!Q.empty()) {
            if (Q.size() > 1) return false;
            int u = Q.front();
            Q.pop();
            for (auto &[v, i]: g[u]) {
                if (i >= k) continue;
                if (!--deg[v]) Q.emplace(v);
            }
        }
        return true;
    };

    int lo = 0, hi = m + 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << (lo > m ? -1 : lo) << endl;
}
