/*
不妨默认 d >= 0，如果 d < 0，则 d = -d, swap(a, b)
对于 x[b] - x[a] = d 这个条件，使用两条边来建模：
- a -> b 连接长为 d 的边, 用于刻画 x[b] <= x[a] + d 这个条件
- b -> a 连接长为 -d 的边, 用于刻画 x[a] <= x[b] - d 这个条件
从 0 往每个点连一条为 0 的边，然后从 0 开始跑单源最短路，如果存在负环则无解

羊の解：不连 0 的边，剩下的还是按上面的连，则对于每个连通分量，只要确定一个点的值，其他点的通过一遍 DFS 都能跑出来，检查所有条件是否都满足即可
*/

struct Edge {
    int v, w;
};

vector<vector<Edge>> e(N);
int n, m, cnt[N];
LL d[N];
bool inqueue[N];

bool spfa(int st) {
    queue<int> q;
    for (int i = 0; i <= n; i++) {
        inqueue[i] = false;
        cnt[i] = 0;
        d[i] = INFLL;
    }
    q.push(st);
    cnt[st]++;
    d[st] = 0;
    int mx = 200;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inqueue[u] = false;
        for (auto edge : e[u]) {
            int v = edge.v, w = edge.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (!inqueue[v]) {
                    q.push(v);
                    inqueue[v] = true;
                    cnt[v]++;
                    if (cnt[v] > mx) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}   

void meibao() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        e[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        if (d < 0) {
            d = -d;
            swap(a, b);
        }
        e[a].push_back({b, d});
        e[b].push_back({a, -d});
    }

    for (int i = 0; i <= n; i++) {
        e[0].push_back({i, 0});
    }

    if (spfa(0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}   
