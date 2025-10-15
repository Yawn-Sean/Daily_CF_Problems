// 1126
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    nums.push_back(0);

    for (int i = n; i > 0; --i) {
        nums[i] -= nums[i - 1];
    }

    // for (auto x : nums) {
    //     std::cerr << x << ' ';
    // }

    std::vector<int> left;
    std::vector<int> right;

    for (int idx = 0; idx <= n; ++idx) {
        if (nums[idx] >= 0) {
            for (int val = 0; val < nums[idx]; ++val) {
                left.push_back(idx);
            }
        } else {
            for (int val = 0; val < -nums[idx]; ++val) {
                right.push_back(idx - 1);
            }
        }
    }

    std::cout << ssize(left) << '\n';
    for (int i = 0; i < ssize(left); ++i) {
        std::cout << left[i] + 1 << ' ' << right[i] + 1 << '\n';
    }

    return 0;
}