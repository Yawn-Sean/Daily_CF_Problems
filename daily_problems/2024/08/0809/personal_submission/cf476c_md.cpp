// 0809
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    std::cin >> a >> b;

    constexpr int mod = 1e9 + 7;
    i64 ret = ((1ll * a * (a + 1) / 2 % mod) * b % mod + a) % mod * (1ll * b * (b - 1) / 2 % mod) % mod;
    std::cout << ret << '\n';
    return 0;
}