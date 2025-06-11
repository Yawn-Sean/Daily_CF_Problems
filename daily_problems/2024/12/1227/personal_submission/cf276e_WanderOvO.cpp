/*
对于 1 号点的每个儿子 u，做链上 dfs 记录 u 链每个点的深度，以及标记属于 u 链
对于操作 1，先看 v 点在哪个链上，以及 v 点深度 depth[v]
如果 depth[v] > d，说明只影响 u 链，没影响到 1 以及其他链
从这条链的第 depth[v] - d 深度，加到 min(depth[v] + d, maxdepth) 深度
如果 depth[v] <= d，说明还影响到其他链
首先是 1 被加了 1 次，然后每条链从上往下被影响了 d - depth[v] 个点，也就是从深度 1 到深度 d - depth[v]
使用专门的结构维护所有链被统一加了多少
为了方便处理 1，我们把 1 的深度在这里看成 1，然后事实上就是加深度 1 到深度 d - depth[v] + 1
查询时，先确定 v 是哪条链的，得到其深度，单点查树状数组，然后再单点查公共的树状数组的对应深度的和
*/

vector<vector<int>> e(N);
int n, q, depth[N], maxdepth[N], fa[N];
vector<BIT> ts(N);

int dfs(int u, int f, int d) {
    depth[u] = d;
    if (f == 1) {
        fa[u] = u;
    } else {
        fa[u] = fa[f];
    }

    int res = d;
    for (auto v : e[u]) {
        if (v != f) {
            res = max(res, dfs(v, u, d + 1));
        }
    }
    return res;
}

void meibao() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (auto u : e[1]) {
        int maxd = dfs(u, 1, 1);
        maxdepth[u] = maxd;
        ts[u].init(maxd + 1);
    }
    ts[1].init(n + 1);
    while (q--) {
        int op, v, x, d;
        cin >> op;
        if (op == 0) {
            cin >> v >> x >> d; 
            int u = fa[v];
            if (depth[v] > d) {
                int l = depth[v] - d, r = min(depth[v] + d, maxdepth[u]);
                ts[u].add(l, x);
                ts[u].add(r + 1, -x);
            } else {
                int r = d - depth[v] + 1;
                ts[1].add(1, x);
                ts[1].add(r + 1, -x);
                ts[u].add(1, -x);
                ts[u].add(min(r, maxdepth[u] + 1), x);
                ts[u].add(1, x);
                r = min(depth[v] + d, maxdepth[u]);
                ts[u].add(r + 1, -x);
            }
        } else {
            cin >> v;
            if (v == 1) {
                cout << ts[1].query(1) << "\n";
            } else {
                int res = 0;
                int u = fa[v];
                res = ts[u].query(depth[v]);
                res += ts[1].query(depth[v] + 1);
                cout << res << "\n";
            }
        }
    }
}
