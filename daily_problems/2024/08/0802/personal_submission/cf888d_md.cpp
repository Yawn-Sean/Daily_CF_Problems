// 0802
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    auto comb = [](int n, int k) -> i64 {
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;
        i64 res = 1;
        for (int i = 1; i <= k; ++i) {
            res = res * (n - i + 1) / i;
        }
        return res;
    };

    auto d = [&](auto self, i64 n) -> i64 {
        if (n == 0 || n == 1) return 0;
        if (n == 2) return 1;
        return (n - 1) * (self(self, n - 1) + self(self, n - 2));
    };

    i64 ret = 1;
    for (int i = 0; i <= k; ++i) {
        ret += comb(n, i) * d(d, i);
    }

    std::cout << ret << '\n';
    return 0;
}