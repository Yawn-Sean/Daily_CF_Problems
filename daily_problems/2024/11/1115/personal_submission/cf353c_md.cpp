// 1115
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    int sum = 0;
    for (auto& x : nums) {
        std::cin >> x;
        sum += x;
    }

    std::string s;
    std::cin >> s;
    int suffix = std::accumulate(begin(nums), end(nums), 0);
    int cur = 0;
    for (int i = std::ssize(s) - 1; i >= 0; --i) {
        if (s[i] == '1') {
            suffix -= nums[i];
            cur = std::max(cur, suffix);
            suffix += nums[i];
        } else {
            suffix -= nums[i];
        }
    }

    std::cout << std::max(cur, suffix) << '\n';

    return 0;
}