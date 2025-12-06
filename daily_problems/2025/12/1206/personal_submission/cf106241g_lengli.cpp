#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

static const i64 mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> vis(n, 0);
    vector<vector<int>> path(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;                // ★ Python 的 GMI() 是 0-based，这里必须减 1！

        path[u].push_back(v);
        path[v].push_back(u);

        vis[u] = 1;
        vis[v] = 1;
    }

    int pt = 0;
    vector<int> to_check;

    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            pt++;
            vis[i] = pt;   // 重新编号 1..pt
            to_check.push_back(i);
        }
    }

    vector<i64> dp(pt + 1, 0);
    dp[ vis[0] ] = 1;   // dp[0-based mapping of node 0]

    vector<i64> res;

    for (int i = 0; i < n; i++) {
        i64 total = 0;
        for (int j = 0; j <= pt; j++) {
            total += dp[j];
            if (total >= mod) total -= mod;
        }

        if (i > 0) res.push_back(total);

        vector<i64> ndp(pt + 1, 0);

        for (int j = 1; j <= pt; j++)
            ndp[j] = total;

        ndp[0] = (i64)(n - pt) * total % mod;

        for (int u : to_check) {
            int cu = vis[u];
            i64 val = dp[cu];
            for (int v : path[u]) {
                int cv = vis[v];
                ndp[cv] = (ndp[cv] - val) % mod;
                if (ndp[cv] < 0) ndp[cv] += mod;
            }
        }

        for (int j = 0; j <= pt; j++) {
            ndp[j] = (ndp[j] - dp[j]) % mod;
            if (ndp[j] < 0) ndp[j] += mod;
        }

        dp.swap(ndp);
    }

    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << (i + 1 == (int)res.size() ? '\n' : ' ');
    }
    return 0;
}
