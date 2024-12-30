// 0722
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    std::sort(begin(nums), end(nums));

    std::vector<i64> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = nums[i + 1] - nums[i];
    }
    std::sort(begin(d), end(d));

    std::vector<i64> acc(ssize(d) + 1);
    for (int i = 1; i <= ssize(d); ++i) {
        acc[i] = acc[i - 1] + d[i - 1];
    }

    int q;
    std::cin >> q;
    while (q--) {
        i64 lk, rk;
        std::cin >> lk >> rk;
        auto dis = rk - lk + 1;

        auto idx = lower_bound(begin(d), end(d), dis) - begin(d);
        std::cout << acc[idx] + (n - idx) * dis << ' ';
    }

    return 0;
}