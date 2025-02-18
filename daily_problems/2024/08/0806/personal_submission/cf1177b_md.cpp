// 0806
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 k;
    std::cin >> k;
    --k;

    i64 base = 9;
    i64 width = 1; 
    while (k >= base * width) {
        k -= base * width;
        base *= 10;
        ++width;
    }

    i64 offset = k / width;
    i64 remain = std::pow(10, width - k % width - 1);
    std::cout << (offset / remain + (k % width  == 0)) % 10 << '\n';

    return 0;
}