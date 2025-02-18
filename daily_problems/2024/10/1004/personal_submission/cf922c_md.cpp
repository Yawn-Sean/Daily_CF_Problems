// 1004
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, k;
    std::cin >> n >> k;

    for (i64 i = 1; i <= k; ++i) {
        if (n % i != i - 1) {
            std::cout << "NO\n";
            return 0;
        }
    }
    std::cout << "YES\n";

    return 0;
}