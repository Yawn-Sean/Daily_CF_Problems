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
        int n;
        cin >> n;

        vector<int> us, vs;
        vector<vector<int>> path(n);

        for (int i = 0; i < n - 1; i ++) {
            int u, v;
            cin >> u >> v;
            u --, v --;
            us.push_back(u);
            vs.push_back(v);
            path[u].push_back(i);
            path[v].push_back(i);
        }

        vector<int> size(n, 1), ans;

        function<void(int, int)> dfs = [&] (int u, int p) {
            for (auto &i: path[u]) {
                if (i == p) continue;
                int v = us[i] ^ vs[i] ^ u;
                dfs(v, i);
                if (size[v] == 0) ans.push_back(i + 1);
                size[u] += size[v];
            }
            if (size[u] == 3) size[u] = 0;
        };

        dfs(0, -1);

        if ((ans.size() + 1) * 3 == n) {
            cout << ans.size() << '\n';
            for (auto &x: ans) cout << x << ' ';
            cout << '\n';
        }
        else cout << "-1\n";
    }

    return 0;
}