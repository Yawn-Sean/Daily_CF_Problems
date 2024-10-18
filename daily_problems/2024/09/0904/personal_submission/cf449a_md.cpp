// 0904
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    auto calc = [&](i64 width) -> i64 {
        auto height = 1ll * m / std::max(1ll, 0ll + k - (n / width - 1) + 1);
        return height * width;
    };

    i64 ret = 0;
    for (int i = 1; i <= n && i <= n / i; ++i) {
        ret = std::max(ret, calc(i));
        ret = std::max(ret, calc(n / i));
    }

    if (ret == 0) {
        std::cout << "-1\n";
    } else {
        std::cout << ret << '\n';
    }
    return 0;
}
