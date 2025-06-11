// 1017
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    i64 avg = 0;
    i64 positives = 0;
    i64 negatives = 0;
    for (int i = 0; i < m; ++i) {
        int xi, di;
        std::cin >> xi >> di;
        avg += xi;
        if (di >= 0) {
            positives += di;
        } else {
            negatives += di;
        }
    }

    i64 sum = 0;
    sum += positives * n * (n - 1) / 2;
    for (int i = 0; i < n; ++i) {
        sum += negatives * std::abs(i - n / 2);
    }

    std::cout << std::setprecision(10) << std::fixed << static_cast<long double>(sum) / n + avg << '\n';

    return 0;
}