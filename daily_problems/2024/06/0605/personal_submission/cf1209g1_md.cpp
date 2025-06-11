// 0605
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> nums(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(nums));

    constexpr int MAX_N = 2e5 + 5;
    std::vector<int> cnt(MAX_N, 0);
    std::vector<int> right_most(MAX_N, 0);
    for (int i = 0; i < n; ++i) {
        int x = nums[i];
        right_most[x] = i;
        ++cnt[x];
    }

    int cost {n};
    for (int i = 0; i < n; ++i) {
        int x = nums[i];
        int r = right_most[x];
        int keep = cnt[x];
        for (int j = i; j <= r; ++j) {
            keep = std::max(keep, cnt[nums[j]]);
            r = std::max(r, right_most[nums[j]]);
        }

        cost -= keep;
        i = r;
    }

    std::cout << cost << std::endl;
    return 0;
}