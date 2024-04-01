// 进行拓扑排序找环，剩下每个环找出最小值作为代价QAQ
void solve() {
    int n;
    cin >> n;

    std::vector<int> c(n), g(n), deg(n), st(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        g[i]--;
        deg[g[i]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    while (q.size()) {
        auto p = q.front();
        q.pop();
        deg[g[p]]--;
        if (deg[g[p]] == 0) {
            q.push(g[p]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0)
            continue;
        int u = i;
        int cur = inf;
        while (deg[u] != 0) {
            deg[u] = 0;
            cur = min(cur, c[u]);
            u = g[u];
        }

        ans += cur;
    }

    cout << ans << '\n';
}
