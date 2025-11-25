/*
考虑 1 号点，在树中其到所有其他点的距离 = 原图中的最短路
所以这棵树一定是 1 号点的最短路径树
同理，对任何一个点 u 来说，这棵树都是 u 的最短路径树
只考虑 1 号点，能求出来一堆最短路径树，无法确定下来具体某个是对所有点都可行的
通过画图，我们有一种感觉
我们考虑 (u, v), 看 w(u, v) 是否 < 最短路径树中 u v 的距离
如果满足，则说明现在的树不够好，需要断掉某一条，换成 (u, v)
但断了某个边之后，还能保证 1 到它的最短路吗？
以及，断哪条边？
假设 w(u, v) < dist(u, v)，说明 (u, v) 这条边就是 u 和 v 的最短路
假设我们断的是 1 到 u 的路径上的边，则 1 到 u 现在只能先通过 v 再到 u 了
即 d[u] = d[v] + w(u, v)，这个 d[u] 应该和之前的 d[u] 相等
然后，考虑原本最短路径树中 u 的父亲结点 fa，假如 fa != 1
假如这条边还保留着，那么现在的 d[fa] = d[v] + w(u, v) + w(u, fa) = d[u] + w(u, fa)
而原来的 d[fa] 是严格小于 < d[u] 的，所以 1 到 fa 的最短路被破坏了
所以，假如发现 w(u, v) 更优时，必须断 u 和父亲的边，或 v 和父亲的边
还得保证 d[u] == d[v] + w(u, v) 或者 d[v] == d[u] + w(u, v)
*/

struct Edge {
    LL v, w;
};

LL n, m, d[N];
bool vis[N];
vector<vector<Edge>> e(N);
LL pre[N], len[N];
vector<vector<Edge>> tr(N);
LL depth[N], lg[N], fa[N][20];

void dijkstra(int st) {
    memset(vis, 0, sizeof vis);
    memset(d, 0x3f, sizeof d);
    
    d[st] = 0;
    priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
    pq.push({d[st], st});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        int u = tp.second;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (auto edge : e[u]) {
            LL v = edge.v, w = edge.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pre[v] = u;
                len[v] = w;
                pq.push({d[v], v});
            } 
        }
    }
}

void init_fa(int u, int f, int d) {
    depth[u] = d;
    if (u != 1) {
        fa[u][0] = f;
        for (int i = 1; i <= lg[d]; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
    }
    
    for (auto edge : tr[u]) {
        LL v = edge.v, w = edge.w;
        init_fa(v, u, d + 1);
    } 
}

LL lca(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    
    while (depth[x] > depth[y]) {
        x = fa[x][lg[depth[x] - depth[y]]];
    }
    
    if (x == y) return x;
    
    for (int i = lg[depth[x]]; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    
    return fa[x][0];
}

LL get_length(int x, int y) {
    int anc = lca(x, y);
    return d[x] + d[y] - 2 * d[anc];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        LL u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    
    dijkstra(1);
    // for (int i = 2; i <= n; i++) {
        // cout << pre[i] << " " << len[i] << "\n";
    // }
    
    for (int i = 2; i <= n; i++) {
        tr[pre[i]].push_back({i, len[i]});
    }
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    init_fa(1, 0, 0);
    
    bool ok = true;
    for (int u = 1; u <= n; u++) {
        for (auto edge : e[u]) {
            LL v = edge.v, w = edge.w;
            if (get_length(u, v) > w) {
                ok = false;
                break;
            }
        }
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
