/*
如果从 1 到 n 要走的路的条数 >= k，则我们可以考虑走一些绕远的路
这个时候走得路越多，前 k 小的代价就越小，所以可以把 1 和 n 所在连通块里面所有的边都走了
如果从 1 到 n 要走的路的条数 < k，则还需要求一个走的边数 < k 的最短路
如果最短路本来就 >= k 条边了，那么说明 < k 条边的路只会更长，一定不如所有边都走了取 k 个最小的
统一一下做法
我们只需要无脑求最短路，不管它走几条边，以及无脑看这个连通块里面前 k 小的边
答案一定是二者之一
*/

struct Edge {
    LL u, v, c;

    bool operator<(const Edge &o) const {
        return c < o.c;
    }
};

int n, m, k, fa[N], vis[N];
LL d[N];
vector<vector<PLL>> e(N);
vector<Edge> edges;

int find(int x) {
    if (x == fa[x]) {
        return x;
    }
    return fa[x] = find(fa[x]);
}

bool together(int x, int y) {
    return find(x) == find(y);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}

void dijkstra(int st) {
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }

    priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
    pq.push({0, st});
    d[st] = 0;
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        int u = tp.second;
        if (vis[u]) {
            continue;
        }

        vis[u] = 1;
        for (auto edge : e[u]) {
            LL v = edge.first, c = edge.second;
            if (d[v] > d[u] + c) {
                d[v] = d[u] + c;
                pq.push({d[v], v});
            }
        }
    }
}

void meibao() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        LL u, v, c;
        cin >> u >> v >> c;
        e[u].push_back({v, c});
        e[v].push_back({u, c});
        merge(u, v);
        edges.push_back({u, v, c});
    }

    dijkstra(1);
    LL res = d[n];
    // cout << res << endl;
    vector<LL> choices;
    for (auto edge : edges) {
        int u = edge.u;
        if (together(1, u)) {
            choices.push_back(edge.c);
        }
    }
    sort(choices.begin(), choices.end());
    int cnt = choices.size();
    cnt = min(cnt, k);
    LL sum = 0;
    for (int i = 0; i < cnt; i++) {
        sum += choices[i];
    }
    cout << min(sum, res) << '\n';
}   
