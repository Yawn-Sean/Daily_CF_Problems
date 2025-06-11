int n, m;
vector<vector<int>> e(M);
vector<PII> edges;
LL cnt[3][M], d[3][M];
LL pass_cnt[M];

void bfs(int st, LL cnt[], LL d[]) {
    bool vis[M] = {false};
    cnt[st] = 1;
    queue<int> q;
    vis[st] = true;
    q.push(st);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : e[u]) {
            if (!vis[v]) {
                vis[v] = true;
                d[v] = d[u] + 1;
                cnt[v] = cnt[u];
                q.push(v);
            } else {
                if (d[v] == d[u] + 1) {
                    cnt[v] += cnt[u];
                }
            }
        }
    }
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        edges.push_back({u, v});
    }

    bfs(1, cnt[1], d[1]);
    bfs(n, cnt[2], d[2]);

    for (int i = 0; i < m; i++) {
        int u = edges[i].x, v = edges[i].y;
        if (d[1][u] + d[2][v] + 1 == d[1][n]) {
            pass_cnt[u] += cnt[1][u] * cnt[2][v];
            pass_cnt[v] += cnt[1][u] * cnt[2][v];
        }

        if (d[1][v] + d[2][u] + 1 == d[1][n]) {
            pass_cnt[u] += cnt[1][v] * cnt[2][u];
            pass_cnt[v] += cnt[1][v] * cnt[2][u];
        }
    }

    double res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, (1.0 * pass_cnt[i]) / cnt[1][n]);
    }
    cout << setprecision(15) << res << "\n";
}  
