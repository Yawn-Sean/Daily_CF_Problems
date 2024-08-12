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

// 存图方式巩固
void solve() {
    int n, m;
    cin >> n >> m;
    vi us(m), vs(m), flow(m), totflow(n), dir(m, -1);
    vvi path(n);
    rep (i, 0, m) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        us[i] = u;
        vs[i] = v;
        flow[i] = c;
        totflow[u] += c;
        totflow[v] += c;
        path[u].push_back(i);
        path[v].push_back(i);
    }
    // 先计算出条件，访问到满足条件的点直接入栈
    rep (i, 0, n) totflow[i] /= 2;
 
    vector<int> st(1);
    while (!st.empty()) {
        int u = st.back(); st.pop_back();
        for (int i: path[u]) {
            if (dir[i] == -1) {
                int v = us[i] + vs[i] - u;
                dir[i] = vs[i] == u;
                totflow[v] -= flow[i];
                if (totflow[v] == 0 && v != n - 1) st.push_back(v);
            }
        }
    }
    printv(dir, nl, false);
}
