// 1011
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> requests(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> requests[i];
    }

    std::vector<i64> left(n, 0);
    std::vector<i64> right(n, 0);

    auto prev_left = requests;
    for (int i = 1; i < n; ++i) {
        left[i] = left[i - 1];
        if (prev_left[i] <= prev_left[i - 1]) {
            left[i] += prev_left[i - 1] - prev_left[i] + 1;
            prev_left[i] = prev_left[i - 1] + 1;
        }
    }

    auto prev_right = requests;
    for (int i = n - 2; i >= 0; --i) {
        right[i] = right[i + 1];
        if (prev_right[i] <= prev_right[i + 1]) {
            right[i] += prev_right[i + 1] - prev_right[i] + 1;
            prev_right[i] = prev_right[i + 1] + 1;
        }
    }

    i64 ret = right[0];
    for (int i = 0; i < n; ++i) {
        i64 leftcost = i > 0 ? left[i - 1] : 0;
        i64 rightcost = i + 1 < n ? right[i + 1] : 0;
        ret = std::min(ret, leftcost + rightcost + std::max(0ll, std::max(prev_left[i], prev_right[i]) - requests[i]));
    }

    std::cout << ret << '\n';

    return 0;
}