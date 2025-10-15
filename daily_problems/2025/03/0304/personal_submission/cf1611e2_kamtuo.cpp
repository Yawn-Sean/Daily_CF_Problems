/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-03-04 18:08                         */
/* Software : Visual Studio Code                            */
/*                                                          */
/*  ██╗  ██╗ █████╗ ███╗   ███╗████████╗██╗   ██╗ ██████╗   */
/*  ██║ ██╔╝██╔══██╗████╗ ████║╚══██╔══╝██║   ██║██╔═══██╗  */
/*  █████╔╝ ███████║██╔████╔██║   ██║   ██║   ██║██║   ██║  */
/*  ██╔═██╗ ██╔══██║██║╚██╔╝██║   ██║   ██║   ██║██║   ██║  */
/*  ██║  ██╗██║  ██║██║ ╚═╝ ██║   ██║   ╚██████╔╝╚██████╔╝  */
/*  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝   ╚═╝    ╚═════╝  ╚═════╝   */
/*----------------------------------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t --) {
        int n, k;
        cin >> n >> k;
        vector x(k + 1, 0);
        vector dep(n + 1, 0), minp(n + 1, 0x3f3f3f3f);
        for (int i = 1; i <= k; i ++) cin >> x[i], minp[x[i]] = 0;
        int ans = 0;
        bool ok = false;
        vector edge(n + 1, vector<int> ());
        for (int i = 1; i < n; i ++) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        } 
        // debug("minp:", minp);
        std::function<void (int, int)> dfs = [&] (int now, int fa) {
            for (int i = 0; i < edge[now].size(); i ++) {
                if (edge[now][i] == fa) continue;
                dep[edge[now][i]] = dep[now] + 1;
                dfs(edge[now][i], now);
                minp[now] = min(minp[now], minp[edge[now][i]] + 1); 
            }
        };
        std::function<void (int, int)> dfs2 = [&] (int now, int fa) {
            if (minp[now] <= dep[now]) {
                ans ++;
                return;
            }
            if (now != 1 && edge[now].size() == 1) {
                ok = true;
                return;
            }
            for (int i = 0; i < edge[now].size(); i ++) {
                if (edge[now][i] == fa) continue;
                dfs2(edge[now][i], now);
            }
        };
        dfs(1, 0);
        dfs2(1, 0);
        if (ok) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n"; 
        }
    }
    return 0;
}

#endif

/*

*/
