/*
先看能不能仅用 <= k 的边组成树，如果能则可以对树上的边进行替换，答案就是边权和 k 的最近距离
如果不能组成，则必须用到 > k 的边，则我们在 MST 中把 > k 的边变成 k 的代价都算出来即可
*/

struct Edge {
    int u, v, s;

    bool operator<(const Edge &e) const {
        return s < e.s;
    }
};

int T;
int n, m, k;
int fa[N];
vector<Edge> e;

int find(int x) {
    if (x == fa[x]) return x;
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

void solve1() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    e.clear();
    for (int i = 1; i <= m; i++) {
        int u, v, s;
        cin >> u >> v >> s;
        e.pb({u, v, s});
    }
    sort(e.begin(), e.end());
    LL res1 = 0;
    int mx = 0;
    for (auto &edge : e) {
        if (!together(edge.u, edge.v)) {
            merge(edge.u, edge.v);
            mx = max(mx, edge.s);
            if (edge.s > k) {
                res1 += edge.s - k;
            }
        }
    }
    if (mx > k) {
        cout << res1 << "\n";
        return;
    }
    LL res2 = INF;
    for (auto &edge : e) {
        LL ch = abs(edge.s - k);
        res2 = min(res2, ch);
    }
    cout << res2 << "\n";
    
}                                                                                                              
