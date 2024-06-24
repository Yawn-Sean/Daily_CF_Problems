// 0527
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int MOD = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<i64> nums(n);
    copy_n(istream_iterator<i64>(std::cin), n, begin(nums));

    sort(begin(nums), end(nums));

    i64 ans = 0;
    i64 cur_sum = 0;
    vector<int> dp(5001);
    dp[0] = 1;
    for (auto num : nums) {
        for (i64 j = 0; j <= cur_sum; ++j) {
            ans += (dp[j] * max(num, (j + num + 1) / 2)) % MOD;
            ans %= MOD;
        }

        for (i64 j = cur_sum; j >= 0; --j) {
            if (j + num <= 5000) {
                dp[j + num] += dp[j];
                dp[j + num] %= MOD;
            }
        }

        cur_sum += num;
    }

    cout << ans << '\n';

    return 0;
}