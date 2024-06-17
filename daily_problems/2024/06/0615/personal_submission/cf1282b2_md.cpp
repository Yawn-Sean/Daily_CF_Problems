// 0615
#include <bits/stdc++.h>

void solve() {
    int n, p, k;
    std::cin >> n >> p >> k;
    std::vector<int> nums(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(nums));

    std::sort(begin(nums), end(nums));
    std::vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i >= k) {
            dp[i] = dp[i - k] + nums[i - 1];
        } else {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }

    for (int i = n; i >= 0; --i) {
        if (dp[i] <= p) {
            std::cout << i << std::endl;
            return;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}