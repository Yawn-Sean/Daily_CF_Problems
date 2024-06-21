#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> path(n);

    while (m --) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    vector<int> target(n);

    for (int i = 0; i < n; i ++)
        cin >> target[i];
    
    vector<int> ans;

    function<void(int)> dfs = [&] (int u) {
        ans.push_back(u);
        target[u] --;
        for (auto &v: path[u]) {
            target[v] --;
            if (target[v] == 0) dfs(v);
        }
    };

    for (int i = 0; i < n; i ++)
        if (target[i] == 0) dfs(i);
    
    cout << ans.size() << '\n';
    for (auto &x: ans) cout << x + 1 << ' ';

    return 0;
}