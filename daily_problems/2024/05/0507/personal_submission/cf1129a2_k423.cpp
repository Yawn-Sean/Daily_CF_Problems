// https://codeforces.com/contest/1129/submission/259817779

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (v < u) v += n;
        g[u - 1].emplace_back(v - 1);
    }
    vector<int> f(n * 2);
    for (int i = 0; i < n; ++i) {
        if (!g[i].empty()) {
            f[i] = ranges::min(g[i]) + n * (g[i].size() - 1);
            f[i + n] = f[i] + n;
        }
    }
    deque<int> Q;
    for (int i = 0; i + 1 < n * 2; ++i) {
        while (!Q.empty() && f[Q.back()] <= f[i]) Q.pop_back();
        while (!Q.empty() && Q.front() <= i - n) Q.pop_front();
        Q.emplace_back(i);
        if (i >= n - 1) {
            cout << f[Q.front()] - (i - (n - 1)) << " \n"[i == n * 2 - 2];
        }
    }
}
