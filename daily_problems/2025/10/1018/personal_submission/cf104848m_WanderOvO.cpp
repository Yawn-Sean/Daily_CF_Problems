/*
点数不多，边数很多
在 T 秒内到达即可，但需要最小化罚款数量
由于速度可以无穷大，所以 T 秒内一定可以到达
因为每条边是按最大速度去算的代价，所以边上不如一直是最大速度
l / v, c * v
sum(l[i] / v[i]) <= T
sum(c[i] * v[i]) 最小
l / v 是反比例函数，v 越大，l 变小的速度越慢
如果是一条链，怎么做？相当于要走哪些边已经确定了
对于 l 比较小或者 c 比较大的边，我们让它的速度小一点
如何调整速度，条件极值
看一下样例 2
9 / v1 + 1 / v2 = 10
v1 + 1000 * v2 最小
9 / v1 = (10 * v2 - 1) / v2
v1 = 9 * v2 / (10 * v2 - 1)
9 * v2 / (10 * v2 - 1) + 1000 * v2 最小

羊：已经确定了路径的情况下，考虑柯西不等式
*/ 

struct Edge {
    LL v, l, c;
};

LL n, m, t;
double d[N];
bool vis[N];
vector<vector<Edge>> e(N);

void dijkstra(int st) {
    priority_queue<PDI, vector<PDI>, greater<PDI>> pq;

    for (int i = 1; i <= n; i++) {
        d[i] = 1e13;
        vis[i] = false;
    }

    d[st] = 0;
    pq.push({0, st});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        int u = tp.y;
        if (vis[u]) continue;

        vis[u] = true;
        for (auto edge : e[u]) {
            int v = edge.v;
            double w = sqrt(edge.l * edge.c);
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

void meibao() {
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++) {
        LL u, v, l, c;
        cin >> u >> v >> l >> c;
        e[u].push_back({v, l, c});
        e[v].push_back({u, l, c});
    }

    dijkstra(1);

    cout << setprecision(15) << d[n] * d[n] / t;
}   
