// 0902
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, mod;
    std::cin >> a >> b >> mod;

    int s1 = static_cast<int>(1e9) % mod;
    int rem = 0;
    for (int i = 0; i <= a && i < mod; ++i) {
        if (rem > b) {
            auto val = std::to_string(i);
            std::cout << "1 " << std::string(9 - ssize(val), '0') << val << '\n';
            return 0;
        }
        rem = (rem + mod - s1) % mod;
    }

    std::cout << "2\n";
    return 0;
}