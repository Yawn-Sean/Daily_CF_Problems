/*
考虑所有的三个点的选择，有 C(n, 3) 种
考虑每条边会贡献几次
我们枚举边 (u, v)，然后考虑这条边在某种选择下贡献 1/2/3 次时有多少种点的选法
通过观察，在任何需要走 (u, v) 的选法中，(u, v) 都应该恰好被走 2 次
那么，有多少种选法能够让 (u, v) 被走呢？
不妨假设 u 是 v 的父亲，则：
- 有一个点是 u，或者不在 u 的子树中，然后另外两个点都在 v 子树中
  这种情况有 C(n - sz[u] + 1, 1) * C(sz[v], 2) 种选法
- 有两个点是 u，或者不在 u 的子树中，然后第三个点在 v 子树中
  这种情况有 C(n - sz[u] + 1, 2) * C(sz[v], 1) 种选法
所以 (u, v) 这条边的贡献期望次数就是这两个加起来 / C(n, 3)
这样，可以算出初始的期望
后面改边时，只需要撤销这条边之前长度的贡献，再重算一下新长度的贡献即可
*/

struct Edge {
    LL u, v, w;
};

int T;
LL n, q, sz[N];
vector<PLL> e[N];
Edge edges[N];
map<PLL, LL> ids;
double contrib[N];

LL C(LL a, LL b) {
    if (b > a) {
        return 0;
    }
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    if (b == 2) {
        return a * (a - 1) / 2;
    }
    return a * (a - 1) * (a - 2) / 6;
}

void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto &v : e[u]) {
        if (v.x != fa) {
            dfs(v.x, u);
            sz[u] += sz[v.x];
        }
    }
    for (auto &v : e[u]) {
        if (v.x != fa) {
            int uu = u, vv = v.x;
            int id = ids[{uu, vv}];
            if (uu > vv) {
                id = ids[{vv, uu}];
            }
            contrib[id] = 
                2 * (C(n - sz[vv], 1) * C(sz[vv], 2) + C(n - sz[vv], 2) * C(sz[vv], 1)) / (1.0 * C(n, 3));
        }
    }
}

void solve1() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        e[edges[i].u].pb({edges[i].v, edges[i].w});
        e[edges[i].v].pb({edges[i].u, edges[i].w});
        int u = edges[i].u, v = edges[i].v;
        if (u > v) {
            swap(u, v);
        }
        ids[{u, v}] = i;
    }
    
    dfs(1, 0);
    double res = 0;
    for (int i = 1; i < n; i++) {
        // cout << contrib[i] << "\n";
        res += edges[i].w * contrib[i];
    }
    cin >> q;
    while (q--) {
        LL id, new_w;
        cin >> id >> new_w;
        res -= edges[id].w * contrib[id];
        edges[id].w = new_w;
        res += edges[id].w * contrib[id];
        printf("%.10lf\n", res);
    }
}     