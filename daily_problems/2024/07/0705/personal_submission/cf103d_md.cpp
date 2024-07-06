// 0705
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> nums(n);
    std::copy_n(std::istream_iterator<i64>(std::cin), n, begin(nums));
    int p;
    std::cin >> p;

    int threshold = 500;
    std::vector<i64> ans(p);
    std::vector<std::vector<std::pair<int, int>>> batch_calc(threshold);
    for (int idx = 0; idx < p; ++idx) {
        int t, k;
        std::cin >> t >> k;
        --t;

        if (k >= threshold) {
            for (int j = t; j < n; j += k) {
                ans[idx] += nums[j];
            }
        } else {
            batch_calc[k].emplace_back(idx, t);
        }
    }
    
    std::vector<i64> acc(n);
    for (int i = 1; i < threshold; ++i) {
        if (empty(batch_calc[i])) {
            continue;
        }

        for (int j = n - 1; j >= 0; --j) {
            if (j + i >= n) {
                acc[j] = nums[j];
            } else {
                acc[j] = acc[j + i] + nums[j];
            }
        }

        for (auto[idx, t] : batch_calc[i]) {
            ans[idx] = acc[t];
        }
    }

    for (int i = 0; i < p; ++i) {
        std::cout << ans[i] << '\n';
    }

    return 0;
}