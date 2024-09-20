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
    vector<int> degs(n);

    while (m --) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        if (u > v) swap(u, v);
        path[u].emplace_back(v);
        degs[u] ++, degs[v] ++;
    }

    vector<int> dp(n, 1);

    for (int i = 0; i < n; i ++) {
        for (auto &j: path[i]) {
            dp[j] = max(dp[j], dp[i] + 1);
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i ++) {
        ans = max(ans, 1ll * dp[i] * degs[i]);
    }
    cout << ans;

    return 0;
}