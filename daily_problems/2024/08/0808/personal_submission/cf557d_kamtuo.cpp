/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-08 19:01 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    const int N = n + 1, M = (m + 1) << 1;
    vector ne(M, 0), d(M, 0), h(N, 0), col(N, -1);
    vector ro(N, 0);
    int idx = 1, root = 0;
    auto add = [&] (int u, int v) -> void {
        ne[idx] = h[u];
        d[idx] = v;
        h[u] = idx ++;
    }; 
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    bool ok = false;
    auto dfs = [&] (auto&& dfs, int now, int fa) -> void {
        ro[now] = root;
        for (int i = h[now]; i; i = ne[i]) {
            if (col[d[i]] == -1) {
                col[d[i]] = col[now] ^ 1;
                dfs(dfs, d[i], now);
            } else if (col[d[i]] == col[now]) ok = true;
        }
    };
    for (int i = 1; i <= n; i ++) {
        if (col[i] == -1) {
            ++ root;
            col[i] = 1;
            dfs(dfs, i, -1);
        }
    }
    bool big = false;
    vector sz(N, 0); 
    for (int i = 1; i <= n; i ++) {
        sz[ro[i]] ++;
    }
    int tw = 0, on = 0;
    for (int i = 1; i <= root; i ++) {
        if (sz[i] == 2) tw ++;
        if (sz[i] == 1) on ++;
        if (sz[i] > 2) big = true;
    }
    if (ok) cout << "0 1" << endl;
    else if (!big) {
        if (tw) {
            cout << 2 << ' ';
            cout << 1ll * (n - 2) * tw << endl;
        } else {
            cout << 3 << ' ';
            cout << 1ll * n * (n - 1) * (n - 2) / 6 << endl;
        }
    } else {
        cout << 1 << ' ';
        LL ans = 0;
        vector c(2, vector(root + 1, 0));
        for (int i = 1; i <= n; i ++) {
            c[col[i]][ro[i]] ++;
        }
        for (int i = 1; i <= root; i ++) {
            ans += 1ll * c[0][i] * (c[0][i] - 1) / 2 + 1ll * c[1][i] * (c[1][i] - 1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}

#endif

/*

*/
