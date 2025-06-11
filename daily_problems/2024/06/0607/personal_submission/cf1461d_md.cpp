// 0607
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> nums(n);
    std::copy_n(std::istream_iterator<i64>(std::cin), n, std::begin(nums));
    std::sort(begin(nums), end(nums));

    std::vector<i64> prefix_sum(n + 1);
    std::partial_sum(begin(nums), end(nums), next(begin(prefix_sum)));

    std::vector<std::pair<int, int>> segs { {0, n - 1} };
    std::set<i64> sums;

    while (!empty(segs)) {
        std::vector<std::pair<int, int>> new_segs;
        for (auto [l, r] : segs) {
            sums.insert(prefix_sum[r + 1] - prefix_sum[l]);

            if (nums[l] == nums[r]) {
                continue;
            }

            auto mid = (nums[l] + nums[r]) / 2;
            auto idx = std::upper_bound(begin(nums) + l, begin(nums) + r + 1, mid) - begin(nums);
            new_segs.emplace_back(l, idx - 1);
            new_segs.emplace_back(idx, r);
        }
        segs = std::move(new_segs);
    }

    while (q--) {
        i64 s;
        std::cin >> s;
        if (sums.contains(s)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
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