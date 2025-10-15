/*
分层图，第一层是正常边权，第二层是一半的边权
假如 u 点有一匹马，就从 u 往第二层的 u 连一条边长为 0 的有向边
从 1 和 n 分别跑分层图最短路
然后看二者同时到某个点 i，或者一个到 i 另一个到第二层的 i
*/

struct Edge {
    LL v, w;
};

LL d[2][N], n, m, h;
bool vis[N];
vector<vector<Edge>> e(N);

void meibao() {
    cin >> n >> m >> h;
    for (int i = 1; i <= 2 * n; i++) {
        e[i].clear();
    }
    for (int i = 1; i <= h; i++) {
        int a;
        cin >> a;
        e[a].push_back({a + n, 0});
    }

    for (int i = 1; i <= m; i++) {
        LL u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
        e[u + n].push_back({v + n, w / 2});
        e[v + n].push_back({u + n, w / 2});
    }

    dijkstra(1, d[0]);
    dijkstra(n, d[1]);
    if (d[0][n] > INFLL / 2) {
        cout << "-1\n";
    } else {
        LL res = INFLL;
        for (int i = 1; i <= 2 * n; i++) {
            LL val1 = d[0][i];
            if (i + n <= 2 * n) {
                val1 = min(val1, d[0][i + n]);
            }
            LL val2 = d[1][i];
            if (i + n <= 2 * n) {
                val2 = min(val2, d[1][i + n]);
            }
            LL cur = max(val1, val2);
            res = min(res, cur);
        }
        cout << res << "\n";
    }
}
