/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-06 17:49 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector fa(21, vector(n + 1, 0));
    vector dep(n + 1, 0), ne((n + 1) << 1, 0), h(n + 1, 0), d((n + 1) << 1, 0);
    int idx = 1;
    std::function<void (int, int)> add = [&] (int u, int v) -> void {
        ne[idx] = h[u];
        d[idx] = v;
        h[u] = idx ++;
    };
    for (int i = 2; i <= n; i ++) {
        int u;
        cin >> u;
        add(u, i);
        add(i, u);
    }
    std::function<void (int, int)> dfs = [&] (int now, int pre) -> void { 
        fa[0][now] = pre;
        for (int i = 1; i <= 20; i ++) {
            fa[i][now] = fa[i - 1][fa[i - 1][now]];
        }
        for (int i = h[now]; i; i = ne[i]) {
            if (d[i] == pre) continue;
            dep[d[i]] = dep[now] + 1;
            dfs(d[i], now);
        }
    };
    dep[1] = 1;
    dfs(1, 0);
    std::function<int (int , int)> lca = [&] (int u, int v) -> int {
        if (dep[u] < dep[v]) std::swap(u, v);
        for (int i = 20; i >= 0; i --) {
            if (dep[fa[i][u]] >= dep[v]) u = fa[i][u];
        }
        if (u == v) return u;
        for (int i = 20; i >= 0; i --) {
            if (fa[i][u] != fa[i][v]) {
                u = fa[i][u];
                v = fa[i][v];
            }
        }
        return fa[0][u];
    };
    for (int i = 1; i <= q; i ++) {
        int u, v, t;
        cin >> u >> v >> t;
        int t1 = lca(u, v);
        int t2 = lca(u, t);
        int t3 = lca(v, t);
        int cnt1 = dep[u] + dep[v] - 2 * dep[t1];    
        int cnt2 = dep[u] + dep[t] - 2 * dep[t2];    
        int cnt3 = dep[v] + dep[t] - 2 * dep[t3];    
        int x = (cnt1 - cnt2 + cnt3) / 2;
        // debug("cnt1:", cnt1, "cnt2:", cnt2, "cnt3:", cnt3);
        int y = cnt1 - x;
        int z = cnt3 - x;
        cout << max(max(x, y), z) + 1 << endl;
    }
    return 0;
}

#endif

/*

*/
