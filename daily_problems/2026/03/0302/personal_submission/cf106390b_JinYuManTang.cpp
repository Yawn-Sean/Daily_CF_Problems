// dfs
void solve1() {
    int n;
    cin >> n;
    vector<vector<pair<int, i64>>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> depths(n);
    vector<i64> dis(n);
    auto cal = [&](auto &cal, int u, int fa) -> void {
        for (auto [v, w]: g[u]) {
            if (v == fa) continue;
            depths[v] = depths[u] + 1;
            dis[v] = dis[u] + w;
            cal(cal, v, u);
        }
    };
    cal(cal, 0, -1);

    vector<i64> min_dis(n + 1, inf);
    for (int i = 0; i < n; i++) {
        chmin(min_dis[depths[i]], dis[i]);
    }

    vector<i64> res(n);
    auto dfs = [&](auto& dfs, int u, int fa) -> void {
        chmin(res[u], min_dis[depths[u]]);
        for (auto [v, w]: g[u]) {
            if (v == fa) continue;
            res[v] = res[u] + w;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 0, -1);
    for (int i = 0; i < n; i++) {
        cout << res[i] << " \n"[i == n - 1];
    }
}

// 虚点+分层图dij
void solve2() {
    int n;
    cin >> n;
    vector<vector<pair<int, i64>>> g(3 * n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        g[u + n].push_back({v + n, w});
        g[v + n].push_back({u + n, w});
    }

    vector<int> depths(n);
    auto cal = [&](auto &cal, int u, int fa) -> void {
        for (auto [v, w]: g[u]) {
            if (v == fa) continue;
            depths[v] = depths[u] + 1;
            cal(cal, v, u);
        }
    };
    cal(cal, 0, -1);

    for (int i = 1; i < n; i++) {
        int d = depths[i];
        g[2 * n + d].push_back({i, 0});
        g[i + n].push_back({2 * n + d, 0});
    }

    vector<i64> dis(3 * n, inf);
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
    dis[0] = 0;
    dis[n] = 0;
    pq.push({0, 0});
    pq.push({0, n});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u]) {
            continue;
        }
        for (auto [v, w]: g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dis[i] << " \n"[i == n - 1];
    }
}
