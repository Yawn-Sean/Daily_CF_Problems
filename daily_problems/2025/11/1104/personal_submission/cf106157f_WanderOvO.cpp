/*
或许可以考虑枚举路径上最低的点是谁
只保留超过这个高度的点和边，然后相当于要最小化最大值从 1 走到 2
边数是 5e4，如果跑最短路的话，不到 1e6 的计算量
给了 3.5 秒，枚举最小点然后跑最短路就是不到 5e9 的计算量，可能是可以通过的
最短路是最大值最短路，需要改一下最短路算法的逻辑
*/

int n, h[N], m;
vector<vector<int>> e(N);
int dist[N];
bool vis[N];

int dijkstra(int min_h) {
    if (h[1] < min_h || h[2] < min_h) {
        return INF;
    }
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        vis[i] = false;
    }

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    dist[1] = h[1];
    pq.push({dist[1], 1});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();

        int u = tp.second;
        
        if (vis[u]) continue;
        
        vis[u] = true;
        
        for (auto v : e[u]) {
            if (h[v] >= min_h) {
                if (dist[v] > max(dist[u], h[v])) {
                    dist[v] = max(dist[u], h[v]);
                    pq.push({dist[v], v});
                }
            }
        }
    }
    return dist[2];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int res = INF;
    for (int i = 1; i <= n; i++) {
        int min_h = h[i];
        int max_h = dijkstra(min_h);
        res = min(res, max_h - min_h);
    }
    cout << res << endl;
}
