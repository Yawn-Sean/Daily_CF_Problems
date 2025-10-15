/*
有重边，无自环
不只是最短路，还要考虑走到的点的出租车情况
要最小化的是费用
走非简单路径会更差吗？并非，甚至有可能只有走到某个点，拿到了一个很牛逼的车之后，才可能走到终点
从前往后考虑，当前在 u 点，并且我在 u 点换了一辆车，则我中途不再换车，最终能到的点 v 有什么条件？
d[u][v] <= t[u]
我们连边 (u, v, c[u])，建一个关于费用的新图，再跑一个最短路
*/

struct Edge {
    LL v, w;
};

int n, m, st, ed;
vector<vector<Edge>> dist_e(M), cost_e(M);
LL t[M], c[M];
LL d[M][M];

void dijkstra(int st, LL d[], vector<vector<Edge>> &e) {
    for (int i = 1; i <= n; i++) {
        d[i] = INFLL;
    }

    vector<int> vis(n + 1, 0);

    d[st] = 0;
    priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        int u = tp.y;

        if (vis[u]) continue;
        vis[u] = 1;

        for (auto edge : e[u]) {
            int v = edge.v;
            LL w = edge.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

void meibao() {
    cin >> n >> m >> st >> ed;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist_e[u].push_back({v, w});
        dist_e[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++) {
        dijkstra(i, d[i], dist_e);
    }

    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j != i) {
                if (d[i][j] <= t[i]) {
                    cost_e[i].push_back({j, c[i]});
                }
            }
        }
    }

    dijkstra(st, d[st], cost_e);
    if (d[st][ed] > INFLL / 2) {
        cout << "-1\n";
    } else {
        cout << d[st][ed] << "\n";
    }
}
