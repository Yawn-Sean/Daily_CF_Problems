// 1018
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        ans ^= val;
    }

    // The reminder can group into (0, 1, 2, 3), (5, 6, 7, 8), (9, 10, 11, 12), ...
    // prefix_xor[i] = 0 ^ 1 ^ 2 ^ ... ^ i, or use the following smart formula
    // from https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/10/1018/solution/cf424c.md
    auto prefix_xor = [](auto x) -> int {
        if (x % 4 == 0) {
            return x;
        } else if (x % 4 == 1) {
            return 1;
        } else if (x % 4 == 2) {
            return x + 1;
        } else {
            return 0;
        }
    };
    
    for (int i = 1; i <= n; ++i) {
        auto x = n % (2 * i);
        if (x < i) {
            // the reminder is (0, 1, 2, ... x) that only appear once
            ans ^= prefix_xor(x);
        } else {
            // the reminder has 2 parts
            // 0, 1,     2, ..     i - 1
            // i, i + 1, i + 2, .. x, which is 0, 1, 2, ... x - i
            ans ^= prefix_xor(i - 1) ^ prefix_xor(x - i);
        }
    }

    std::cout << ans << '\n';


    return 0;
}