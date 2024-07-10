#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> path(n);

    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    int cnt = 0;
    vector<int> size(n, 1), colors(n);

    function<void(int, int)> dfs = [&] (int u, int p) {
        cnt += colors[u];
        for (auto v: path[u])
            if (v != p) {
                colors[v] = colors[u] ^ 1; 
                dfs(v, u);
                size[u] += size[v];
            }
    };

    dfs(0, -1);

    long long ans = 1ll * cnt * (n - cnt);
    for (auto x: size) ans += 1ll * x * (n - x);
    cout << ans / 2;

    return 0;
}