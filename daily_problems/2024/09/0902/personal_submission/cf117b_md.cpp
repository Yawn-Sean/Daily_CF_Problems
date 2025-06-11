// 0902
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 a, b, mod;
    std::cin >> a >> b >> mod;

    constexpr i64 offset = static_cast<i64>(1e9);
    i64 s2 = 0;
    for (i64 i = 0; i <= a && i < mod; ++i) {
        s2 = (mod - (i * offset) % mod) % mod;
        if (s2 > b) {
            auto val = std::to_string(i);
            std::cout << "1 " << std::string(9 - ssize(val), '0') << val << '\n';
            return 0;
        }
    }

    std::cout << "2\n";
    return 0;
}