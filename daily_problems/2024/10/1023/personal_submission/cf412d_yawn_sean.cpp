#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std; 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> path(n);

    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
    }

    vector<char> vis(n, 0);

    auto dfs = [&] (auto self, int u) {
        if (vis[u]) return ;
        vis[u] = 1;
        for (auto &v: path[u])
            self(self, v);
        cout << u + 1 << ' ';
    };

    for (int i = 0; i < n; i ++)
        dfs(dfs, i);

    return 0;
}