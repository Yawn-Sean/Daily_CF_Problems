// 0607
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, k, l, m;
    std::cin >> n >> k >> l >> m;

    if (m == 1 || (l <= 60 && k >= (1ll << l))) {
        std::cout << 0 << "\n";
        return 0;
    }

    // |f(n+1), f(n)| = |[1, 1]|^n
    // |f(n), f(n-1)|   |[1, 0]|
    std::vector<std::vector<i64>> mat {{1ll, 1ll}, {1ll, 0ll}};
    auto mat_ret = mat_pow(mat, n + 1, m); 

    // Need to get F_{n+2}
    auto c0 = mat_ret[0][0];
    auto c1 = modpow<i64>(2ll, n, m) - c0;

    i64 ret = 1ll;
    for (i64 i = 0; i < l; ++i) {
        if ((k >> i) & 1) {
            ret *= c1;
            ret %= m;
        } else {
            ret *= c0;
            ret %= m;
        }
    }

    std::cout << (ret + m) % m << "\n";

    return 0;
}