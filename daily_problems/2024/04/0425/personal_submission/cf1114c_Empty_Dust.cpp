#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

i64 cal(i64 x, i64 n) {
    i64 ret = 0, y = x;
    while (1) {
        ret += n / y;
        if (y <= n / x)y *= x;
        else break;
    }
    return ret;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 n, b;std::cin >> n >> b;
    if (n == 1) {
        std::cout << 0;
        return 0;
    }
    i64 ans = 1e18;
    for (int i = 2;i <= std::sqrt(b);++i)if (b % i == 0) {
        int div = 0;
        while (b % i == 0)div++, b /= i;
        ans = std::min(ans, cal(i, n) / div);
    }
    if (b > 1) {
        ans = std::min(ans, cal(b, n));
    }
    std::cout << ans;
    return 0;
}
