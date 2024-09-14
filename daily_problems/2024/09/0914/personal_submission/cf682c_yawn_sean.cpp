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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<int> edge(n, 0);
    vector<vector<int>> tree(n);

    for (int i = 1; i < n; i ++) {
        int p;
        cin >> p >> edge[i];
        p --, tree[p].emplace_back(i);
    }

    vector<int> dp(n, 0), stk = {0};
    int ans = 0, upper = 1e9 + 5;

    while (!stk.empty()) {
        int u = stk.back();
        stk.pop_back();
        ans ++;

        for (auto v: tree[u]) {
            dp[v] = max(0, dp[u]) + edge[v];
            if (dp[v] <= nums[v]) stk.emplace_back(v);
        }
    }
    cout << n - ans;

    return 0;
}