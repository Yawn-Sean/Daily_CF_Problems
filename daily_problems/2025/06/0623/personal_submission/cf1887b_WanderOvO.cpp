/*
每条边维护自己可以在哪些时间被走，空间足够
d[i]: 到达 i 的最短时间，这也说明至少到 d[i] + 1 才能继续走
u 走到 v，如何更新？
需要看 (u, v) 这条边中，>= d[u] + 1 的最小时间，这就是一个能到达 v 的时间
具体如何做？首先要看 (u, v) 这条边在哪个组，然后要看这条边所在的组能动的时间
*/

int d[N], n, t, k, a[N];
bool vis[N];
vector<vector<PII>> groups(N);
vector<vector<PII>> e(N);
vector<vector<int>> can_move_time(N);

void meibao() {
    cin >> n >> t;
    for (int i = 1; i <= t; i++) {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back({v, i});
            e[v].push_back({u, i});
        }
    }

    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        can_move_time[a[i]].push_back(i);
    }

    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        int u = tp.y;
        if (vis[u]) continue;
        vis[u] = true;
        int st_time = d[u] + 1;
        for (auto &edge : e[u]) {
            int v = edge.x, group = edge.y;
            auto pos = lower_bound(can_move_time[group].begin(), can_move_time[group].end(), st_time);
            if (pos != can_move_time[group].end()) {
                int new_t = *pos;
                if (new_t < d[v]) {
                    d[v] = new_t;
                    pq.push({d[v], v});
                }
            }
        }
    }

    if (d[n] > k) {
        d[n] = -1;
    }
    cout << d[n];
}
