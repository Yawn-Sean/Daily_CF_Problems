// 0819
#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    int m = (n - 1) / k;
    int rem = (n - 1) % k;
    int cnt = 2 * m + std::min(rem, 2);

    std::cout << cnt << '\n';
    for (int i = 2; i <= k + 1; ++i) {
        std::cout << i << " " << 1 << '\n';
    }

    for (int i = k + 2; i <= n; ++i) {
        std::cout << i << " " << i - k << '\n';
    }

    return 0;
}