// 0913
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;

    i64 f0 = 1, f1 = 2, f2 = 3;
    // f0, f1, f2 = f0 + f1, f3 = f1 + f2
    int ret = 1;
    while (f2 <= n) {
        f0 = f1;
        f1 = f2;
        f2 = f0 + f1;
        ++ret;
    }

    std::cout << ret << '\n';
    return 0;
}