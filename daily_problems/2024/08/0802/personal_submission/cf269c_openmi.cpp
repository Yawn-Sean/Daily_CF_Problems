void solve() {
    int n, m;
    cin >> n >> m;
    vi dir(m, -1), flow(m);
    vvc<pii> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c, d = -1;
        cin >> u >> v >> c;
        --u, --v;
        flow[i] = c;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, ~i);
    }
    queue<int> qu;
    qu.push(0);
    while (!qu.empty()) {
        auto u = qu.front(); qu.pop();
        int inflow = 0, totflow = 0, flag;
        for (auto [v, i]: g[u]) {
            if (i < 0) flag = 1, i = ~i;
            else flag = 0;
            
            if (dir[i] != -1 and dir[i] ^ flag) {
                inflow += flow[i];
            }
            totflow += flow[i];
        }
        if (u == 0 || inflow == totflow - inflow) {
            for (auto [v, i]: g[u]) {
                if (i < 0) flag = 1, i = ~i;
                else flag = 0;
                
                if (dir[i] == -1) {
                    dir[i] = flag;
                    if (v != n - 1) qu.push(v);
                }
            }
        }
    }
    printv(dir, nl, false);
}
