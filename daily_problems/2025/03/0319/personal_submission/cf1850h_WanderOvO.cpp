/*
方法 1：带权并查集
保证 d >= 0，否则 swap(a, b)，d = -d
a 往右走 d 步到达 b：
- a b 不在同一个集合里面，则直接 merge，并维护 dist[a] 为 a 到集合代表元的距离
- a b 在同一个集合里面，则判断 a 到 b 的距离是否真的是 d，这需要算 dist[a] - dist[b]
*/

int n, m, fa[N];
LL dist[N];

int find(int x) {
    if (x == fa[x]) {
        return x;
    }

    int f = find(fa[x]);
    dist[x] += dist[fa[x]];
    fa[x] = f;
    return f;
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        dist[i] = 0;
    }
    bool ok = true;
    for (int i = 1; i <= m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        if (d < 0) {
            d = -d;
            swap(a, b);
        }
        int faa = find(a);
        int fab = find(b);
        if (faa != fab) {
            fa[faa] = fab;
            LL d1 = dist[a], d2 = dist[b];
            // d1 - d2 + x = d => x = d - d1 + d2
            dist[faa] += d - d1 + d2;
        } else {
            if (dist[a] - dist[b] != d) {
                ok = false;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";
}   


/*
方法 2：差分约束
不妨默认 d >= 0，如果 d < 0，则 d = -d, swap(a, b)
对于 x[b] - x[a] = d 这个条件，使用两条边来建模：
- a -> b 连接长为 d 的边, 用于刻画 x[b] <= x[a] + d 这个条件
- b -> a 连接长为 -d 的边, 用于刻画 x[a] <= x[b] - d 这个条件
从 0 往每个点连一条为 0 的边，然后从 0 开始跑单源最短路，如果存在负环则无解
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
