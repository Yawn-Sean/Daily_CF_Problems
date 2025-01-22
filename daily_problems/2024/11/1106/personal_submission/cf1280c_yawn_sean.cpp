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

    int t;
    cin >> t;

    while (t --) {
        int n, k;
        cin >> k;
        n = k * 2;

        vector<vector<array<int, 2>>> path(n);
        for (int i = 0; i < n - 1; i ++) {
            int u, v, w;
            cin >> u >> v >> w;
            u --, v --;

            path[u].push_back({v, w});
            path[v].push_back({u, w});
        }

        long long mi = 0, ma = 0;

        auto dfs = [&] (auto &self, int u, int p, int w) -> int {
            int sz = 1;
            for (auto &v: path[u]) {
                if (v[0] != p) {
                    sz += self(self, v[0], u, v[1]);
                }
            }
            mi += (sz & 1 ? w : 0);
            ma += 1ll * min(n - sz, sz) * w;
            return sz;
        };

        dfs(dfs, 0, -1, 0);
        cout << mi << ' ' << ma << '\n';
    }

    return 0;
}