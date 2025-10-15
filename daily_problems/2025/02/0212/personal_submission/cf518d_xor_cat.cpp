#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

using real = long double;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed;

    int n, t;
    real p;
    std::cin >> n >> p >> t;

    std::vector<real> f(n + 1);
    f[0] = 1;
    for (int x = 0; x < t; x++) {
        for (int i = n - 1; i >= 0; i--) {
            f[i + 1] += p * f[i];
            f[i] = (1 - p) * f[i];
        }
    }

    real ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += f[i] * i;
    }

    std::cout << std::setprecision(6) << ans << "\n";

    return 0;
}
