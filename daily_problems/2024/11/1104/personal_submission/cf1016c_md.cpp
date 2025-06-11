// 1104
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> row1(n), row2(n);
    for (auto& x : row1) {
        std::cin >> x;
    }

    for (auto& x : row2) {
        std::cin >> x;
    }

    std::vector<i64> acc1(n + 1), acc2(n + 1);
    std::partial_sum(begin(row1), end(row1), begin(acc1) + 1);
    std::partial_sum(begin(row2), end(row2), begin(acc2) + 1);

    std::vector<i64> dp1(n + 1), dp2(n + 1);    
    // dp[i] meaning the maximum score when we start walking from the i-th column to n in row1 and then back to the i-th column in row2
    // dp[i] = 2 * i * row1[i] + (2i + 1) * row1[i + 1] + (2i + 2) * row2[i + 1] + (2i + 3) * row2[i] (where 2i +3 == 2n - 1)
    // considering dp[i + 1] = 2 * (i + 1) * row1[i + 1] + (2(i + 1) + 1) * row2[i + 1]
    // dp[i] + acc1[i+1:n] + acc2[i+1:n] + 2i * row1[i] + 2n-1 * row2[i]
    for (int i = n - 1; i >= 0; --i) {
        i64 extra = acc1[n] - acc1[i + 1] + acc2[n] - acc2[i + 1];
        dp1[i] = dp1[i + 1] - extra + 2 * i * row1[i] + (2 * n - 1) * row2[i];
        dp2[i] = dp2[i + 1] - extra + 2 * i * row2[i] + (2 * n - 1) * row1[i];
    }

    i64 ret = dp1[0];
    i64 cur = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            cur += 2 * i * row2[i] + (2 * i + 1) * row1[i];
            ret = std::max(ret, cur + dp1[i + 1]);
        } else {
            cur += 2 * i * row1[i] + (2 * i + 1) * row2[i];
            ret = std::max(ret, cur + dp2[i + 1]);
        }
    }

    std::cout << ret << '\n';
    return 0;
}