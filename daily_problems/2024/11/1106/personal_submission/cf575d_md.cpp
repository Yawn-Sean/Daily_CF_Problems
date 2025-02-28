// 1106
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int len = 1000;
    std::cout << len * 2 << std::endl;

    for (int i = 1; i <= len; ++i) {
        std::cout << i << " " << 1 << " " << i << " " << 2 << std::endl;
    }

    for (int i = len; i >= 1; --i) {
        std::cout << i << " " << 1 << " " << i << " " << 2 << std::endl;
    }

    return 0;
}