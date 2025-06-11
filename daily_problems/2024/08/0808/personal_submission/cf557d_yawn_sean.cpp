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
    
    if (!m) {
        cout << 3 << ' ' << 1ll * n * (n - 1) * (n - 2) / 6;
        return 0;
    }

    vector<vector<int>> path(n);

    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    vector<int> cols(n, -1);
    int c0, c1;

    auto dfs = [&] (auto &&dfs, int u) -> bool {
        if (cols[u]) c1 ++;
        else c0 ++;
        for (auto &v: path[u]) {
            if (cols[v] == -1) {
                cols[v] = cols[u] ^ 1;
                if (!dfs(dfs, v)) return false;
            }
            else if (cols[u] == cols[v])
                return false;
        }
        return true;
    };

    long long ans = 0;
    for (int i = 0; i < n; i ++) {
        if (cols[i] == -1) {
            c0 = 0, c1 = 0;
            cols[i] = 0;
            if (!dfs(dfs, i)) {
                cout << 0 << ' ' << 1;
                return 0;
            }
            ans += 1ll * c0 * (c0 - 1) / 2 + 1ll * c1 * (c1 - 1) / 2;
        }
    }

    if (ans) cout << 1 << ' ' << ans;
    else cout << 2 << ' ' << 1ll * m * (n - 2);


    return 0;
}