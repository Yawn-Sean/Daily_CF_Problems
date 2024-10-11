#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> path(n);

        while (m --) {
            int u, v;
            string s;
            cin >> u >> v >> s, u --, v --;
            if (s[0] == 'i') path[u].push_back(~v), path[v].push_back(~u);
            else path[u].push_back(v), path[v].push_back(u);
        }

        vector<int> vis(n, -1);
        int cnt, cnt1, ans = 0;
        bool flg = true;

        auto dfs = [&] (auto &&dfs, int u) -> void {
            cnt ++;
            if (vis[u]) cnt1 ++;
            for (auto &v: path[u]) {
                if (v >= 0) {
                    if (vis[v] == -1)
                        vis[v] = vis[u], dfs(dfs, v);
                    else if (vis[v] != vis[u])
                        flg = false;
                }
                else {
                    v = ~v;
                    if (vis[v] == -1)
                        vis[v] = vis[u] ^ 1, dfs(dfs, v);
                    else if (vis[v] == vis[u])
                        flg = false;
                }
            }
        };

        for (int i = 0; i < n; i ++)
            if (vis[i] == -1) {
                cnt = 0, cnt1 = 0;
                vis[i] = 0;
                dfs(dfs, i);
                ans += max(cnt1, cnt - cnt1);
            }
        cout << (flg ? ans : -1) << '\n';
    }

    return 0;
}