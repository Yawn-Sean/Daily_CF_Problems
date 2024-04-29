/*
如果 (u, v) 是最短路上的边，应该满足什么条件才是必经的？
先求一下最短路径图，统计一下最短路上每个点的前驱
对于本来就在最短路上的边(d1[u] + d2[v] + dist == d1[t])：
- 如果恰好满足 cnt1[u] * cnt2[v] % MOD == cnt1[t] % MOD，则说明必经，YES
- 否则，最短路应该变得更短才可能行，修改 (u, v) 一定能使得最短路更短，并且被必经，修改 1 即可
对于不在最短路上的边(d1[u] + d2[v] + dist > d1[t])：
- 一定得比当前最短路还短才行
*/

struct Edge {
    int a, b, c;
};

int T;
int h[N], rh[N], e[M], ne[M], w[M], idx;
int n, m, s, t;
LL d1[N], d2[N], cnt1[N], cnt2[N];
bool st[N];
int MOD;
vector<Edge> edges;

void solve1() {
    cin >> n >> m >> s >> t;
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        edges.pb({a, b, c});
    }
    for (int i = 0; i < m; i++) {
        radd(edges[i].b, edges[i].a, edges[i].c);
    }
    srand(time(NULL));
    MOD = 2 * MOD1 + 1000 + rand() % 1000;
    dijkstra(s, h, e, ne, w, d1, cnt1);
    dijkstra(t, rh, e, ne, w, d2, cnt2);

    for (int i = 0; i < m; i++) {
        int u = edges[i].a, v = edges[i].b, dist = edges[i].c;
        LL c1 = cnt1[u], c2 = cnt2[v];
        if (d1[u] + d2[v] + dist == d1[t]) {
            if (c1 * c2 % MOD == cnt1[t] % MOD) {
                cout << "YES\n";
            } else {
                if (dist > 1) {
                    cout << "CAN 1\n";
                } else {
                    cout << "NO\n";
                }
            }
        } else {
            LL target = d1[t] - 1 - d1[u] - d2[v];
            LL cost = dist - target;
            if (cost < dist) {
                cout << "CAN " << cost << "\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}   