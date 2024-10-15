#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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
        path[v].emplace_back(u);
    }

    vector<vector<int>> diameters(n);
    vector<int> d(n, -n-1), parent(n, -1), q(n * 2);

    for (int i = 0; i < n; i ++) {
        if (d[i] == -n - 1) {
            int l, r;
            l = 0, r = 1;
            q[l] = i, d[i] = -1;
            while (l < r) {
                int u = q[l ++];
                for (auto &v: path[u]) {
                    if (d[v] == -n - 1) {
                        d[v] = d[u] - 1;
                        q[r ++] = v;
                    }
                }
            }
            int x;
            x = q[l - 1];
            l = 0, r = 1;
            q[l] = x, d[x] = 0;
            while (l < r) {
                int u = q[l ++];
                for (auto &v: path[u]) {
                    if (d[v] < 0) {
                        d[v] = d[u] + 1;
                        parent[v] = u;
                        q[r ++] = v;
                    }
                }
            }

            x = q[l - 1];
            int dia = d[x];
            for (int j = 0; j < dia / 2; j ++)
                x = parent[x];
            
            diameters[dia].emplace_back(x);
        }
    }

    vector<pair<int, int>> outs;
    int cur = -1, ma = 0;

    for (int i = n - 1; i >= 0; i --) {
        for (auto u: diameters[i]) {
            if (cur == -1)
                cur = u, ma = i;
            else {
                outs.push_back({cur, u});
                ma = max(ma, (i + 1) / 2 + (ma + 1) / 2 + 1);
            }
        }
    }
    cout << ma << '\n';
    for (auto &[x, y]: outs)
        cout << x + 1 << ' ' << y + 1 << '\n';

    return 0;
}