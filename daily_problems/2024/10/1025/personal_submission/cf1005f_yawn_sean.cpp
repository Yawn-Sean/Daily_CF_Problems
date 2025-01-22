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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> us(m), vs(m);
    vector<vector<int>> path(n);

    for (int i = 0; i < m; i ++) {
        cin >> us[i] >> vs[i];
        us[i] --, vs[i] --;
        path[us[i]].emplace_back(i);
        path[vs[i]].emplace_back(i);
    }

    vector<int> dis(n, -1), dq(n, 0);
    dis[0] = 0;

    int l = 0, r = 1;

    while (l < r) {
        int u = dq[l ++];
        for (auto &i: path[u]) {
            int v = us[i] + vs[i] - u;
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                dq[r ++] = v;
            }
        }
    }

    vector<vector<int>> prev_edges(n);
    int cur = 1;
    for (int u = 1; u < n; u ++) {
        for (auto &i: path[u]) {
            int v = us[i] + vs[i] - u;
            if (dis[u] == dis[v] + 1) {
                prev_edges[u].emplace_back(i);
            }
        }
        cur = 1ll * cur * prev_edges[u].size();
        if (cur > k) cur = k;
    }

    cout << cur << '\n';

    vector<int> chosen_edges(m, 0);

    for (int i = 0; i < cur; i ++) {
        int tmp = i;
        for (int j = 1; j < n; j ++) {
            int idx = tmp % prev_edges[j].size();
            tmp /= prev_edges[j].size();
            chosen_edges[prev_edges[j][idx]] = 1;
        }

        for (auto &x: chosen_edges)
            cout << x;
        cout << '\n';

        for (int j = 0; j < m; j ++)
            chosen_edges[j] = 0;
    }

    return 0;
}