// 0724
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    auto gcd = std::accumulate(begin(nums), end(nums), 0, std::gcd<int, int>);
    if (gcd > 1) {
        std::cout << "YES\n0\n";
    } else {
        int odd = 0;
        int ret = 0;
        for (auto num : nums) {
            if (num & 1) {
                ++odd;
            } else {
                if (odd & 1) {
                    ret += odd / 2 + 2;
                } else {
                    ret += odd / 2;
                }
                odd = 0;
            }
        }

        if (odd & 1) {
            ret += odd / 2 + 2;
        } else {
            ret += odd / 2;
        }
        odd = 0;

        std::cout << "YES\n" << ret << "\n";
    }

    return 0;
}  