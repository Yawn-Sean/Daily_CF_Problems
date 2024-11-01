// 1031
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (auto& v : nums) {
        std::cin >> v;
    }

    int left = 0;
    int ret = 0;
    auto updateLen = [&](int l, int r) {
        ret = std::max(ret, (r - l - 1) /2);
        for (int i = l; i < (l + r) / 2; ++i) {
            nums[i] = nums[l];
        }

        for (int i = (l + r) / 2; i < r; ++i) {
            nums[i] = nums[r - 1];
        }
    };

    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[i - 1]) {
            continue;
        }
        updateLen(left, i);
        left = i;
    }

    updateLen(left, n);
    std::cout << ret << '\n';
    for (auto v : nums) {
        std::cout << v << ' ';
    }

    return 0;
}