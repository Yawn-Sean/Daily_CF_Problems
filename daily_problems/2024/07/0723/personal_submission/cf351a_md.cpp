// 0723
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    double sum = 0.0;
    int zcnt = 0;
    for (int i = 0; i < n * 2; ++i) {
        double x;
        std::cin >> x;
        x = x - (int) x;
        int intx = static_cast<int>(x);
        if (x - intx == 0.0) {
            ++zcnt;
        }
        sum += x;
    }

    double ret = n * 2;
    for (int i = std::max(n - zcnt, 0); i <= std::min(2 * n - zcnt, n); ++i) {
        ret = std::min(ret, std::abs(i - sum));
    }

    std::cout << std::fixed << std::setprecision(3) << ret << '\n';
    return 0;
}