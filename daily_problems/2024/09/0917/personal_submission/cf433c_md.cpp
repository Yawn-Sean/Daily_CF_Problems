// 0917
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums(m);
    std::vector<std::vector<int>> ctrbs(n + 1);
    i64 diff = 0;
    for (int i = 0; i < m; ++i) {
        std::cin >> nums[i];
        if (i > 0) {
            diff += abs(nums[i] - nums[i - 1]);
        }
    }

    for (int i = 0; i < m; ++i) {
        if (i > 0) {
            if (nums[i] != nums[i - 1]) {
                ctrbs[nums[i]].push_back(nums[i - 1]);
            }
        }

        if (i + 1 < m) {
            if (nums[i] != nums[i + 1]) {
                ctrbs[nums[i]].push_back(nums[i + 1]);
            }
        }
    }

    i64 ret = diff;
    for (int i = 1; i <= n; ++i) {
        auto& vals = ctrbs[i];
        if (!empty(vals)) {
            std::sort(begin(vals), end(vals));
            int p = vals[ssize(vals) / 2];

            i64 delta = 0;
            for (int j = 0; j < ssize(vals); ++j) {
                delta += std::abs(vals[j] - p) - std::abs(i - vals[j]);
            }

            ret = std::min(diff + delta, ret);
        }
    }

    std::cout << ret << '\n';

    return 0;
}
