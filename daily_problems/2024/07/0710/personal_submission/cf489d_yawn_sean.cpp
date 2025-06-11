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
        path[u].emplace_back(v);
    }

    vector<int> cnt(n);
    // 这个 int 其实有点冒险，需要估计不会爆 int
    int ans = 0;
    for (int u = 0; u < n; u ++) {
        for (auto &v: path[u]) 
            for (auto &w: path[v])
                cnt[w] += 1;
        for (int v = 0; v < n; v ++) {
            if (v != u)
                ans += cnt[v] * (cnt[v] - 1) / 2;
            cnt[v] = 0;
        }
    }
    cout << ans;

    return 0;
}