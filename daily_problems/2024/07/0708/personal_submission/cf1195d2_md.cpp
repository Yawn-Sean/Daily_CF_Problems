// 0708
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;
constexpr int MOD = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    std::vector<int> cnt(11);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        auto str = std::to_string(nums[i]);
        cnt[ssize(str)]++;
    }

    std::vector<i64> power(25, 1);
    for (int i = 1; i < ssize(power); ++i) {
        power[i] = (power[i - 1] * 10) % MOD;
    }

    i64 ans = 0;
    for (auto num : nums) {
        i64 cur = num;
        i64 trailing = 0;
        for (int len = 1; len <= 10; ++len) {
            trailing = (trailing + cur % 10 * power[len * 2 - 2]) % MOD;
            cur = cur / 10;

            ans += (cur * 10 * power[2 * len - 2] + trailing) * cnt[len] * 10 % MOD;
            ans += (cur * 100 * power[2 * len - 2] + trailing) * cnt[len] % MOD;
        }
    }

    std::cout << ans % MOD << '\n';

    return 0;
}