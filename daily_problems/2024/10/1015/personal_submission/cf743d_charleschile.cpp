#include <iostream>
#include <algorithm>
#include <vector>
// https://codeforces.com/problemset/problem/743/D

int main () {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int &v : nums) {
        std::cin >> v;
    }

    std::vector<std::vector<int>> path(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u;
        std::cin >> v;
        u--, v--;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    // dfs
    std::vector<int> parent(n, -1), order, stk = {0};
    while (!stk.empty()) {
        int u = stk.back();
        stk.pop_back();
        order.push_back(u);

        for (int &v : path[u]) {
            if (parent[u] != v) {
                parent[v] = u;
                stk.emplace_back(v);
            }
        }
    }

    reverse(order.begin(), order.end());

    long long inf = 1e15;
    std::vector<long long> dp(n, 0), dp1(n, -inf), dp2(n, -inf);
    long long ans = -inf;

    for (int &i : order) {
        dp[i] += nums[i];
        if (i > 0) {
            int p = parent[i];
            dp[p] += dp[i];

            long long v = std::max(dp[i], dp1[i]);

            if (v >= dp1[p]) {
                dp2[p] = v;
                std::swap(dp1[p],dp2[p]);
            }
            else if (v > dp2[p]) {
                dp2[p] = v;
            }

            
        }
        if (dp2[i] > -inf) {
                ans = std::max(ans, dp1[i] + dp2[i]);
        }
    }
    
    if (ans > -inf) std::cout << ans;
    else std::cout << "Impossible" << std::endl;


    return 0;
}