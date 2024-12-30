#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s --, t --;

    vector<vector<int>> path(n);

    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    vector<int> que(n);
    int l, r;

    vector<int> dis1(n, -1);
    que[0] = s, l = 0, r = 1, dis1[s] = 0;

    while (l < r) {
        int u = que[l ++];
        for (auto &v: path[u]) {
            if (dis1[v] == -1) {
                dis1[v] = dis1[u] + 1;
                que[r ++] = v;
            }
        }
    }

    vector<int> dis2(n, -1);
    que[0] = t, l = 0, r = 1, dis2[t] = 0;

    while (l < r) {
        int u = que[l ++];
        for (auto &v: path[u]) {
            if (dis2[v] == -1) {
                dis2[v] = dis2[u] + 1;
                que[r ++] = v;
            }
        }
    }

    int target = dis1[t], ans = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            if (min(dis1[i] + dis2[j], dis2[i] + dis1[j]) + 1 >= target)
                ans ++;
        }
    }
    cout << ans - m;

    return 0;
}