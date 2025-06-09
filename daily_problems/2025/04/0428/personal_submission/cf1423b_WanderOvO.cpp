/*
二分天数 ans，然后只考虑天数 <= ans 的边，跑最大流求二分图最大匹配
如果最大流为 n，说明能匹配
*/

struct Edge {
    int u, v, w;

    bool operator<(const Edge &o) const {
        return w < o.w;
    }
};

int n, m;
Edge edges[N];

bool check(int ans) {
    atcoder::mf_graph<int> g(2 * n + 3);
    int s = 2 * n + 1, t = 2 * n + 2;

    for (int i = 1; i <= n; i++) {
        g.add_edge(s, i, 1);
        g.add_edge(i + n, t, 1);
    }

    for (int i = 1; i <= m; i++) {
        if (edges[i].w <= ans) {
            g.add_edge(edges[i].u, n + edges[i].v, 1);
        } else {
            break;
        }
    }

    int res = g.flow(s, t);
    return (res == n);
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges + 1, edges + m + 1);
    int l = 0, r = edges[m].w, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(l)) {
        cout << l << "\n";
    } else if (check(r)) {
        cout << r << "\n";
    } else {
        cout << "-1\n";
    }
}
