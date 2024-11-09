/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-09 13:26 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    vector edge(n + 1, vector<int> ());
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vector sz(n + 1, 0);
    LL ans = 1ll * n * (n - 1);
    std::function<bool (int, int)> dfs = [&] (int now, int fa) -> bool {
        bool ok = false;
        sz[now] = 1;
        if (now == y) ok = true;
        for (auto v : edge[now]) {
            if (v == fa) continue;
            if (dfs(v, now)) {
                ok = true;
                if (now == x) ans -= 1ll * sz[y] * (n - sz[v]); 
            }
            sz[now] += sz[v];
        }
        return ok;
    };
    dfs(x, -1);
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
