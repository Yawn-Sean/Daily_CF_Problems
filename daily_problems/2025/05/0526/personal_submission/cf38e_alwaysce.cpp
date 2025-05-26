#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> xs(n + 1, -1e9-7), cs(n + 1, -1e9-7);
    for (int i = 1; i <= n; ++i) {
        cin >> xs[i] >> cs[i];
    }
    vector<int> order(n + 1);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return xs[i] < xs[j];
    });

    /*
        dp[i][j] <- dp[i - 1][j] + |x[i| - x|j||
        or dp[i][i] <- min(dp[i - 1][?] + cost[i])     
    */
    vector<i64> dp(n + 1, inf), ndp(n + 1, inf);
    dp[1] = cs[order[1]];

    for (int i = 2; i <= n; i++) {
        i64 mn = inf; // 前缀最小值
        for (int j = 1; j < i; j++) {
            mn = min(mn, dp[j]);
        }
        // 固定第 i 个弹珠
        ndp[i] = mn + cs[order[i]];
        for (int j = 1; j < i; j++) {
            // 不固定第 i 个弹珠
            // 上一个固定位置是j
            ndp[j] = min(ndp[j], dp[j] + xs[order[i]] - xs[order[j]]);
        }

        swap(dp, ndp);
        ndp.assign(n + 1, inf);
    }

    i64 ans = inf;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}
