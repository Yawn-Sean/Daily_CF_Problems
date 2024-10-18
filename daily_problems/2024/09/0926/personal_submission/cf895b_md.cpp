// 0926
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, k;
    std::cin >> n >> x >> k;
    std::vector<int> nums(n);
    for (auto& num : nums) {
        std::cin >> num;
    }

    std::sort(begin(nums), end(nums));

    i64 ret = 0;
    for (auto num : nums) {
        i64 l = (num + x - 1) / x + k - 1;
        i64 p1 = l * x;
        i64 p2 = (l + 1) * x;
        int idx1 = std::lower_bound(begin(nums), end(nums), std::max(1ll * num, p1)) - begin(nums);
        int idx2 = std::lower_bound(begin(nums), end(nums), p2) - begin(nums) - 1;
        ret += (idx2 - idx1 + 1);
    }

    std::cout << ret << '\n';

    return 0;
}