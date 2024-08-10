// 0627
#include <bits/stdc++.h>

using i128 =__int128;
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr i64 MAX_NUM = 1e6;

    int n;
    std::cin >> n;
    while (n--) {
        i64 a, b;
        std::cin >> a >> b;
        i128 a128 = a;
        i128 b128 = b;
        i128 prod = a128 * b128;
        i128 l = i128(1);
        i128 r = MAX_NUM;

        while (l + i128(1) < r) {
            i128 mid = (l + r) / 2;
            if (mid * mid * mid <= prod) {
                l = mid;
            } else {
                r = mid;
            }
        }

        if (l * l * l == prod && (a128 % l == 0) && (b128 % l == 0)) {
            std::cout << "Yes\n";
        } else if (r * r * r == prod && (a128 % r == 0) && (b128 % r == 0)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

    return 0;
}