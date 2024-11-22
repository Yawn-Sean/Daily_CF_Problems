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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;
    
    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    vector<int> parent(n, -1), order, stk = {0};

    while (!stk.empty()) {
        int u = stk.back();
        stk.pop_back();

        order.emplace_back(u);

        for (auto &v: path[u]) {
            if (parent[u] != v) {
                parent[v] = u;
                stk.emplace_back(v);
            }
        }
    }

    long long inf = 1e15;

    vector<long long> dp(n, 0), dp1(n, -inf), dp2(n, -inf);
    long long ans = -inf;

    reverse(order.begin(), order.end());

    for (auto &i: order) {
        dp[i] += nums[i];
        if (i > 0) {
            int p = parent[i];
            dp[p] += dp[i];

            long long v = max(dp[i], dp1[i]);
            if (v >= dp1[p])
                dp2[p] = v, swap(dp1[p], dp2[p]);
            else if (v > dp2[p])
                dp2[p] = v;
        }

        if (dp2[i] > -inf)
            ans = max(ans, dp1[i] + dp2[i]);
    }

    if (ans > -inf) cout << ans;
    else cout << "Impossible";

    return 0;
}