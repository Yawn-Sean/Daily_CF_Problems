// 0613
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k, p;
    std::cin >> n >> k >> p;
    std::vector<int> nums(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(nums));

    // Considering acc[i] % p is fixed, acc[j] % p has p values
    // Improve the dp formula from dp[i][k] = max_j in [i,i)(dp[j][k-1] + acc[i] % p - acc[j] % p)
    // To: dp[acc[i]][k] = max(dp[acc[j]][k-1] + acc[i] % p - acc[j] % p)

    std::vector<std::vector<int>> dp(k, std::vector<int>(p + 1, std::numeric_limits<int>::min()));
    dp[0][0] = 0;
    int cur_sum = 0; 
    for (int i = 0; i < n - 1; ++i) {
        cur_sum += nums[i];
        cur_sum %= p;

        for (int l = k - 2; l >= 0; --l) {
            for (int j = 0; j < p; ++j) {
                dp[l + 1][cur_sum] = std::max(dp[l + 1][cur_sum], dp[l][j] + (cur_sum + p - j) % p);
            }
        }
    }

    cur_sum += nums.back();
    cur_sum %= p;

    // Make sure the answer has k segments and constains the last element
    std::transform(begin(dp[k - 1]), end(dp[k - 1]), begin(dp[k - 1]), [cur_sum, modval = 0, p](int x) mutable {
        return x + (cur_sum + p - modval++) % p; 
    });

    std::cout << *std::max_element(begin(dp[k - 1]), end(dp[k - 1])) << std::endl;
    return 0;
}