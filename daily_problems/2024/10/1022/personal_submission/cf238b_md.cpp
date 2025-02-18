// 1022
#include <bits/stdc++.h>
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, h;
    std::cin >> n >> h;
    std::vector<pii> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i].first;
        nums[i].second = i + 1;
    }

    std::sort(begin(nums), end(nums));

    std::vector<int> groups(n + 1, 1);
    // g1, g1, ....., g1, g1
    int minval = nums[0].first + nums[1].first;
    int maxval = nums[n - 1].first + nums[n - 2].first;
    int ret = maxval - minval;

    if (n == 2) {
        std::cout << ret << '\n';
        std::cout << "1 1\n";
        return 0;
    }

    // g2, g1,....., g1, g1
    minval = std::min(nums[0].first + nums[1].first + h, nums[1].first + nums[2].first);
    maxval = std::max(maxval, nums[n - 1].first + nums[0].first + h);
    if (maxval - minval < ret) {
        ret = maxval - minval;
        groups[nums[0].second] = 2;
    } 

    std::cout << ret << '\n';
    for (int i = 1; i <= n; ++i) {
        std::cout << groups[i] << " ";
    }


    return 0;
}