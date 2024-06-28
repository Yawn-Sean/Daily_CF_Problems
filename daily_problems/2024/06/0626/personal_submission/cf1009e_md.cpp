// 0626
#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 MOD = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(nums));

    // for position j, if the cost is a_i (starting from 1), if j == i, p = 2^(-i + 1), 
    // if j > i, for any j >= i + 1, there are n - i contribution of p = 2^i
    // sum_{i = 1}^{n} [2^(-i + 1) + (n - i) * 2 ^ i] * 2 ^ (n - 1) * a[i - 1]

    std::vector<i64> pow2(n + 1, 1);
    pow2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    i64 ret = nums.back();
    for (int i = 1; i <= n - 1; ++i) {
        ret += (pow2[n - i - 1] * (n - i) % MOD + pow2[n - i] % MOD) % MOD * nums[i - 1] % MOD;
        ret %= MOD;
    }

    std::cout << ret << '\n'; 

    return 0;
} 