// 0608
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, m;
    std::cin >> n >> m;

    i64 ans = 0;
    for (i64 i = 1; i <= m; ++i) {
        i64 cnt1 = (n + m - i) / m;
        for (i64 j = 1; j <= m; ++j) {
            if ((i * i + j * j) % m == 0) {
                i64 cnt2 = (n + m - j) / m;
                ans += cnt1 * cnt2;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}