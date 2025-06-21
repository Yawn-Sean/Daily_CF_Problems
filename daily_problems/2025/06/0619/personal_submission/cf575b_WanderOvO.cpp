/*
我们的关注点在于求那些单向边的反向各自被走了多少次
由于是树，所以只有唯一一条路能走
求出 lca 之后，怎么加贡献？树上差分？
方向怎么办？
维护两个不同的差分数组，一个是往上走的差分数组，一个是往下走的差分数组
u -> lca -> v
则向上走的差分数组中，b[u]++, b[lca]--
向下走的差分数组中，b[v]++, b[lca]--
每个 b[i] 描述的是 i 和 fa[i][0] 这条边在某个方向上走了几次
*/

struct Edge {
    LL v, w;
};

const int mod = 1e9 + 7;
LL n, k, lg[N], depth[N], fa[N][M], b[N][2], res = 0, pow2[N];
vector<vector<Edge>> e(N);
set<LL> cost;

void dfs(int u, int f, int d) {
    depth[u] = d;
    fa[u][0] = f;
    for (int i = 1; i <= lg[d]; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }

    for (auto &edge : e[u]) {
        LL v = edge.v;
        if (v != f) {
            dfs(v, u, d + 1);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    while (depth[u] > depth[v]) {
        u = fa[u][lg[depth[u] - depth[v]]];
    }

    if (u == v) {
        return u;
    }

    for (int i = lg[depth[u]]; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }

    return fa[u][0];
}

void calc(int u, int f) {
    for (auto &edge : e[u]) {
        LL v = edge.v, w = edge.w;
        if (v != f) {
            calc(v, u);
            b[u][0] += b[v][0];
            b[u][1] += b[v][1];
        }
    }

    if (f != 0) {
        LL up = (n + 1) * u + f;
        LL down = (n + 1) * f + u;
        if (cost.count(up) && b[u][0]) {
            res += pow2[b[u][0] - 1];
        } 
        if (cost.count(down) && b[u][1]) {
            res += pow2[b[u][1] - 1];
        }
        res %= mod;
    }
}

void meibao() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        LL a, b, w;
        cin >> a >> b >> w;
        if (w == 0) {
            e[a].push_back({b, 0});
            e[b].push_back({a, 0});
        } else {
            e[a].push_back({b, 0});
            e[b].push_back({a, 1});
            cost.insert((n + 1) * b + a);
        }
    }

    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    pow2[0] = 1;
    for (int i = 1; i < N; i++) {
        pow2[i] = pow2[i - 1] * 2;
        pow2[i] %= mod;
    }
    for (int i = 1; i < N; i++) {
        pow2[i] += pow2[i - 1];
        pow2[i] %= mod;
    }

    dfs(1, 0, 1);

    cin >> k;
    int cur = 1;
    while (k--) {
        int s;
        cin >> s;
        int ancestor = lca(cur, s);
        // 0 是向上，1 是向下
        b[cur][0]++;
        b[ancestor][0]--;
        b[s][1]++;
        b[ancestor][1]--;
        cur = s;
    }

    calc(1, 0);

    cout << res << "\n";
}
