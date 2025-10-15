/*
把每个点拆成 1000 个点：(i, min_s)
从 (1, s[1]) 这个点开始跑
(i, min_s) 往邻点 j 跑，则是从 (i, min_s) 转移到 (j, min(min_s, s[j]))，这条边长为 min_s * w
(i, min_s) 对应 1000 * (i - 1) + min_s - 1 这个点
最后是看所有的 (n, min_s) 的最小值
*/

struct Edge {
    int u, v, w;
};

LL n, m, s[M], d[N];
bool vis[N];
vector<vector<PLL>> e(M);

int get_id(int i, int min_s) {
    return (i - 1) * 1000 + min_s - 1;
}

void dijkstra(int st) {
    priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
    for (int i = 0; i <= n * 1002; i++) {
        d[i] = INFLL;
    }
    for (int i = 0; i <= n * 1002; i++) {
        vis[i] = false;
    }
    d[st] = 0;
    pq.push({d[st], st});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();

        LL u = tp.y;
        if (vis[u]) { 
            continue;
        }

        vis[u] = true;
        LL uu = u / 1000 + 1;
        LL min_s = u % 1000 + 1;
        for (auto edge : e[uu]) {
            LL vv = edge.x, w = edge.y;
            LL v = get_id(vv, min(s[vv], min_s));
            d[v] = min(d[v], d[u] + w * min_s);
            if (!vis[v]) {
                pq.push({d[v], v});
            }
        }
    }
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    dijkstra(get_id(1, s[1]));

    LL res = INFLL;
    for (int i = 1; i <= 1000; i++) {
        res = min(res, d[get_id(n, i)]);
    }
    cout << res << "\n";
}  
