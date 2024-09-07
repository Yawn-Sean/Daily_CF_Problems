/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-06 11:59 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    struct EDGE {
        int v;
        LL w;
    };
    vector edge(n + 1, vector<EDGE>());
    struct Node {
        int u, v;
        LL w;
    };
    vector<Node> e(2 * n + 1);
    for (int i = 1; i < n; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
        edge[u].push_back({v, w});     
    }
    vector to(n + 1, 0);
    for (int i = n; i <= 2 * n - 2; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        to[u] = w;
        e[i] = {u, v, w};
    }
    vector sz(n + 1, 0), son(n + 1, 0), dep(n + 1, 0), fa(n + 1, 0);
    dep[0] = -1;
    std::function<void (int)> dfs = [&] (int now) {
        sz[now] = 1;
        for (int i = 0; i < edge[now].size(); i ++) {
            dep[edge[now][i].v] = dep[now] + 1;
            fa[edge[now][i].v] = now;
            dfs(edge[now][i].v);
            if (sz[edge[now][i].v] > sz[son[now]]) son[now] = edge[now][i].v;
            sz[now] += sz[edge[now][i].v];
        }
    };
    const int N = n + 1;
    vector dfn(N, 0), top(N, 0), bu(N, 0), nfd(N, 0);
    vector dist(N, 0ll);
    dfs(1);
    int cnt = 0; 
    top[1] = 1;
    std::function<void (int)> dfs2 = [&] (int now) {
        dfn[now] = ++ cnt;
        nfd[cnt] = now;
        bu[now] = now;
        for (auto v : edge[now]) {
            if (v.v == son[now]) {
                dist[v.v] = dist[now] + v.w;
                top[v.v] = top[now];
                dfs2(v.v);
                bu[now] = bu[v.v];
            }
        }
        for (auto v : edge[now]) {
            if (v.v != son[now]) {
                dist[v.v] = dist[now] + v.w;
                top[v.v] = v.v;
                dfs2(v.v);
            }
        }
    };
    dfs2(1);
    struct Tree {
        int l, r;
        LL w, add, mina;
    };
    vector<Tree> tr((n + 1) << 2);
    auto pushup = [&] (int u) {
        tr[u].w = tr[u << 1].w + tr[u << 1 | 1].w;
        tr[u].mina = min(tr[u << 1].mina, tr[u << 1 | 1].mina);
    };
    auto pushdown = [&] (int u) {
        if (tr[u].add) {
            tr[u << 1].add += tr[u].add;
            tr[u << 1].w += 1ll * (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].add;
            tr[u << 1].mina += tr[u].add;
            tr[u << 1 | 1].add += tr[u].add;
            tr[u << 1 | 1].mina += tr[u].add;
            tr[u << 1 | 1].w += 1ll * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].add;
        }
        tr[u].add = 0;
    };
    std::function<void (int, int, int)> build = [&] (int u, int l, int r) {
        if (l == r) {
            tr[u] = {l, r, dist[nfd[l]], 0, dist[nfd[l]] + to[nfd[l]]};
            return;
        }
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    };
    std::function<void (int, int, int, int)> modify = [&] (int u, int l, int r, LL w) {
        if (l <= tr[u].l && r >= tr[u].r) {
            tr[u].add += w;
            tr[u].w += 1ll * w * (tr[u].r - tr[u].l + 1);
            tr[u].mina += w;
            return; 
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, w);
        if (r > mid) modify(u << 1 | 1, l, r, w);
        pushup(u);
    };
    std::function<void (int, int, int, int)> modify2 = [&] (int u, int l, int r, LL w) {
        if (l <= tr[u].l && r >= tr[u].r) {
            tr[u].mina += w;
            return; 
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify2(u << 1, l, r, w);
        if (r > mid) modify2(u << 1 | 1, l, r, w);
        pushup(u);
    };
    std::function<LL (int, int, int)> query2 = [&] (int u, int l, int r) -> LL {
        if (l <= tr[u].l && r >= tr[u].r) {
            return tr[u].mina;
        }
        LL res = 0x3f3f3f3f3f3f3f3f;
        int mid = tr[u].l + tr[u].r >> 1;
        pushdown(u);
        if (l <= mid) res = min(res, query2(u << 1, l, r));
        if (r > mid) res = min(query2(u << 1 | 1, l, r), res);
        pushup(u);
        return res;
    };
    std::function<LL (int, int, int)> query = [&] (int u, int l, int r) -> LL {
        if (l <= tr[u].l && r >= tr[u].r) {
            return tr[u].w;
        }
        LL res = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        pushdown(u);
        if (l <= mid) res += query(u << 1, l, r);
        if (r > mid) res += query(u << 1 | 1, l, r);
        pushup(u);
        return res;
    };
    build(1, 1, cnt);
    auto lca = [&] (int u, int v) -> int {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]])
                u = fa[top[u]];
            else
                v = fa[top[v]];
        }
        return dep[u] > dep[v] ? v : u;
    };
    for (int i = 1; i <= q; i ++) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 2) {
            int lc = lca(u, v);
            if (lc == u) {
                cout << query(1, dfn[v], dfn[v]) - query(1, dfn[u], dfn[u]) << "\n";
            } else {
                // debug("dfn:", dfn[u], "sz:", sz[u]);
                // debug("u:", u, "2:", query2(1, dfn[u], dfn[u] + sz[u] - 1));
                cout << 1ll * query2(1, dfn[u], dfn[u] + sz[u] - 1) + query(1, dfn[v], dfn[v]) - query(1, dfn[u], dfn[u]) << "\n";
            }
        } else {
            if (u > n - 1) {
                int now = e[u].u;
                modify2(1, dfn[now], dfn[now], v - to[now]);
                to[e[u].u] = v;
            } else {
                int now = e[u].v;
                int w = v - e[u].w;
                e[u].w = v;
                modify(1, dfn[now], dfn[now] + sz[now] - 1, w);
            }
        }
    }
    return 0;
}

#endif

/*

*/
