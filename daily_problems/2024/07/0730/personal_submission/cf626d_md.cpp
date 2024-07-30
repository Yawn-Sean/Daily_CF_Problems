// 0730
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::sort(begin(nums), end(nums));
    const int max_count = 5000;
    std::vector<i64> diffs(max_count);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            diffs[nums[j] - nums[i]]++;
        }
    }

    std::vector<i64> diff_pairs(max_count);
    for (int i = 0; i < max_count; ++i) {
        for (int j = 0; j < max_count; ++j) {
            if (i + j < max_count) {
                diff_pairs[i + j] += diffs[i] * diffs[j]; 
            }
        }
    }

    std::partial_sum(begin(diff_pairs), end(diff_pairs), begin(diff_pairs));

    i64 total = 0;
    for (int i = 1; i < max_count; ++i) {
        total += diff_pairs[i - 1] * diffs[i];
    }

    std::cout << std::fixed << std::setprecision(10) << 1.0 * total / std::pow(n * (n - 1) / 2.0, 3.0) << '\n';
    return 0;
}