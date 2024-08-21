// 0807
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k, x;
    std::cin >> n >> k >> x;
    std::vector<int> nums(n), left(n), right(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        left[i] = nums[i];
        right[i] = nums[i];
    }

    for (int i = 1; i < n; ++i) {
        left[i] = left[i - 1] | nums[i];
    }

    for (int i = n - 2; i >= 0; --i) {
        right[i] = right[i + 1] | nums[i];
    }

    i64 inc = 1;
    for (int i = 0; i < k; ++i) {
        inc *= x;
    }

    i64 ret = 0;
    for (int i = 0; i < n; ++i) {
        i64 cur = nums[i] * inc;
        if (i > 0) {
            cur |= left[i - 1];
        }
        if (i + 1 < n) {
            cur |= right[i + 1];
        }
        ret = std::max(ret, cur);
    }

    std::cout << ret << '\n';
    return 0;
}