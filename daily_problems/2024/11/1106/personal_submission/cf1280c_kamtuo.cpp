/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-06 15:17 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    struct Node {
        int u, t;
    };
    while (t --) {
        int n;
        cin >> n;
        vector edge(2 * n + 1, vector<Node> ());
        LL ans1 = 0, ans2 = 0;
        for (int i = 1; i <= 2 * n - 1; i ++) {
            int u, v, t;
            cin >> u >> v >> t;
            edge[u].push_back({v, t});
            edge[v].push_back({u, t});
        }
        vector sz(2 * n + 1, 0);
        std::function<void (int, int)> dfs = [&] (int now, int fa) {
            sz[now] = 1;
            for (Node v : edge[now]) {
                if (v.u == fa) continue;
                dfs(v.u, now);
                sz[now] += sz[v.u];
                if (sz[v.u] % 2) ans1 += v.t;
                ans2 += 1ll * min(sz[v.u], 2 * n - sz[v.u]) * v.t;
            }
        };
        dfs(1, -1);
        cout << ans1 << ' ' << ans2 << "\n";
    }
    return 0;
}

#endif

/*

*/
